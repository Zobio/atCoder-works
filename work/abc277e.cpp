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
#define dll deque<long long>
#define ddll deque<dque<long long>>
#define dddll deque<deque<deque<long long>>>
#define ddddll deque<deque<deque<deque<long long>>>>
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

int main() {
	ll n, m, k; cin >> n >> m >> k;
	vvpll g(n);
	rep(i, m) {
		ll u, v, a; cin >> u >> v >> a; u--; v--;
		g[u].push_back({v, a}); g[v].push_back({u, a});
	}
	set<ll> sw;
	rep(i, k) {
		ll s; cin >> s; s--; sw.insert(s);
	}
	vvll dist(n, vll(2, INF)); //dist[i][j] : 頂点i,状態jの最短距離
	dist[0][1] = 0;
	queue<pll> que;
	que.push({0, 1});
	while(que.size()) {
		pll cur = que.front(); que.pop();
		for(pll nxt : g[cur.first]) {
			if(cur.second != nxt.second) continue;
			if(chmin(dist[nxt.first][nxt.second], dist[cur.first][cur.second] + 1)) que.push({nxt.first, nxt.second});
		}
		if(sw.count(cur.first)) for(pll nxt : g[cur.first]) {
			if(cur.second == nxt.second) continue;
			if(chmin(dist[nxt.first][nxt.second], dist[cur.first][cur.second] + 1)) que.push({nxt.first, nxt.second});
		}
	}
	cout << (*min_element(all(dist.back())) == INF ? -1 : *min_element(all(dist.back()))) << endl;
}