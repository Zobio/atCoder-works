#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define reep(i, a, b) for(long long i = a; i < b; i++)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;}
#define setcout(n) cout << setprecision(n) << fixed
#define YESS {printf("Yes\n"); return 0;}
#define NOO {printf("No\n"); return 0;}
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define mint modint998244353
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll n;
vvll g;
map<pll, ll> cost;
vector<bool> visited;
vll ans;
vll path; //直径の経路

void dfs1(ll cur, ll sum) {
	cout << cur + 1  << "  " << sum << endl;
	ans[cur] += sum;
	visited[cur] = true;
	fore(nxt, g[cur]) {
		if(visited[nxt]) continue;
		if(cost.find({cur, nxt}) != cost.end()) sum += cost[{cur, nxt}];
		dfs1(nxt, sum);
		sum -= cost[{cur, nxt}];
	}
}

void dfs2(ll cur, ll sum) {
	cout << cur + 1 << "  " << sum << endl;
	ans[cur] += sum;
	visited[cur] = true;
	fore(nxt, g[cur]) {
		if(visited[nxt]) continue;
		bool flag = cost.find({cur, nxt}) != cost.end() && binary_search(all(path), cur) && binary_search(all(path), nxt);
		if(flag) sum += cost[{cur, nxt}]; //2重計算しない
		dfs2(nxt, sum);
		if(flag) sum -= cost[{cur, nxt}];
	}
}

int main() {
	cin >> n;
	vpll ab(n - 1); g.resize(n);
	rep(i, n - 1) {
		ll a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b); g[b].push_back(a);
		ab[i] = {a, b};
	}
	ll q; cin >> q;
	vll t(q), e(q), x(q); rep(i, q) cin >> t[i] >> e[i] >> x[i], e[i]--;
	rep(i, q) {
		if(t[i] == 1) cost[{ab[e[i]].second, ab[e[i]].first}] += x[i];
		else cost[{ab[e[i]].first, ab[e[i]].second}] += x[i];
	}

	//木の直径を求める
	vll dist(n, INF); dist[0] = 0;
	queue<ll> que; que.push(0);
	while(!que.empty()) {
		ll cur = que.front(); que.pop();
		for(auto nxt : g[cur]) {
			if(chmin(dist[nxt], dist[cur] + 1)) que.push(nxt);
		}
	}
	ll st = max_element(all(dist)) - dist.begin();

	//BFS2回目 st-->enのパスも求めておく
	vll pre(n); pre[st] = -1;
	fill(all(dist), INF); dist[st] = 0;
	que.push(st);
	while(!que.empty()) {
		ll cur = que.front(); que.pop();
		for(auto nxt : g[cur]) {
			if(chmin(dist[nxt], dist[cur] + 1)) que.push(nxt), pre[nxt] = cur;
		}
	}
	ll en = max_element(all(dist)) - dist.begin();

	//st --> enのパスを求める

	ll cc = en;
	while(cc != st) path.push_back(cc), cc = pre[cc], cout << cc << endl;
	path.push_back(st);
	sort(all(path));

	visited.resize(n); ans.resize(n);
	dfs1(st, 0);
	cout << endl;
	fill(all(visited), false);
	arrcout(ans);
	dfs2(en, 0);
	rep(i, n) cout << ans[i] << endl;
}