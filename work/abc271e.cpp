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

ll n, m, k;
vvvll g;
vll e;
map<pll, ll> num;//頂点番号

vector<map<ll, ll>> dijkstra(ll s) { 
	vector<map<ll, ll>> dis(g.size()); //頂点、添え字
	priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> que;
	//disを更新するためのqueue first:コスト second:頂点番号 third : eの添え字
	for(auto au : g[0]) {
		que.push({au[1], au[0], au[2]}); //コスト、頂点番号、添え字
		dis[au[0]][au[2]] = au[1];
	}
	while(!que.empty()) {
		auto p = que.top(); que.pop();
		auto [cost, v, soeji] = p;
		rep(i, g[v].size()) {
			ll vv = g[v][i][0], ccost = g[v][i][1], ssoeji = g[v][i][2];
			if(dis[vv].find(ssoeji) == dis[vv].end()) {
				dis[vv][ssoeji] = dis[v][soeji] + ccost;
				que.push({dis[vv][ssoeji], vv, ssoeji});
			}
			else if(dis[vv][ssoeji] >  dis[v][soeji] + ccost) {
				dis[vv][ssoeji] = dis[v][soeji] + ccost;
				que.push({dis[vv][ssoeji], vv, ssoeji});
			}
		}
	}
	return dis;
}

int main() {
	cin >> n >> m >> k;
	g.resize(n);
	rep(i, m) {
		ll u, v, c; cin >> u >> v >> c; u--; v--;
		g[u].push_back({v, c, i});
		num[{u, v}] = i;
	}
	e.resize(k);
	rep(i, k) cin >> e[i], e[i]--;
	vector<map<ll, ll>> ans = dijkstra(0);
	ll mi = INF;
	for(auto au : ans.back()) chmin(mi, au.second);
	cout << (mi == INF ? -1 : mi) << endl;
}