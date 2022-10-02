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

struct edge {
	ll from;
	ll to;
	ll cost;
};

int main() {
	ll n, m, k; cin >> n >> m >> k;
	vector<edge> ed(m);
	rep(i, m) {
		ll u, v, c; cin >> u >> v >> c; u--; v--;
		ed[i] = {u, v, c};
	}
	vll e(k);
	rep(i, k) cin >> e[i], e[i]--;
	vll dp(n, INF); //dp[i][j] : 都市1からjまでの経路で、利用する辺の部分列がE_0 ~ E_iに含まれるものの距離の最小値 サイズ削減のためiの部分はin-placeに更新していく
	//2次元DPテーブルで考えると、dp[i + 1][j] = dp[i][j]という操作が必要だが、1次元に落とし込むとその操作をする必要がない
	dp[0] = 0; //まだ経路をたどっていないとき、最初の都市のみ距離0
	rep(i, k) chmin(dp[ed[e[i]].to], dp[ed[e[i]].from] + ed[e[i]].cost);
	cout << (dp.back() == INF ? -1 : dp.back()) << endl;
}