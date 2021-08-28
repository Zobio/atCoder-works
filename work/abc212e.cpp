#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 998244353LL
#define INF 1LL << 60

int main() {
	ll n, m, k; cin >> n >> m >> k;
	vector<vector<ll>> g(n);
	rep(i, m) {
		ll u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<vector<ll>> dp(k + 1, vector<ll>(n));
	dp[0][0] = 1;
	rep(day, k) {
		ll sum = 0;
		rep(i, n) sum = (sum + dp[day][i]) % MOD;
		rep(i, n) dp[day + 1][i] = (sum - dp[day][i] + MOD) % MOD;
		rep(i, n) {
			for(auto a : g[i]) dp[day + 1][i] = (dp[day + 1][i] - dp[day][a] + MOD) % MOD;
		}
	}
	cout << dp[k][0] << endl;
}