#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n, m; cin >> n >> m;
	vll g(n); // g[i]にはiから向かう有効辺の頂点の集合が保存される
	rep(i, m) {
		ll x, y; cin >> x >> y; x--; y--;
		g[x] |= 1ll << y;
	}
	vll dp(1ll << n);
	dp[0] = 1;
	rep(i, 1ll << n) rep(j, n) {
		if(i & 1 << j && (i & g[j]) == 0){
			//jの有効辺の頂点と今の状態iに1つでも一致しているものがあったらダメ
			dp[i] += dp[i & ~(1 << j)];
		}
	}
	cout << dp[(1ll << n) - 1] << endl;
}