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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n, m; cin >> n >> m;
	vvll g(n);
	rep(i, m) {
		ll u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
	}
	ll s, t; cin >> s >> t; s--; t--;
	queue<pll> que;
	vvll dist(n, vll(3, INF));
	que.push({s, 0}); // s、0歩
	dist[s][0] = 0;
	while(!que.empty()) { //BFS
		ll cur, jmp;
		tie(cur, jmp) = que.front(); que.pop();
		ll nxt_jmp = (jmp + 1) % 3;
		for(auto to : g[cur]) if(dist[to][nxt_jmp] == INF) {
			dist[to][nxt_jmp] = dist[cur][jmp] + 1;
			que.push({to, nxt_jmp});
		}
	}
	cout << (dist[t][0] != INF ? dist[t][0] / 3 : -1) << endl;
}