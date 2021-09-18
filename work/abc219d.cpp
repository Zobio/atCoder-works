#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	ll n, x, y; cin >> n >> x >> y;
	vector<ll> a(n);
	vector<ll> b(n);
	rep(i, n) cin >> a.at(i) >> b.at(i);
	vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(x + 1, vector<ll>(y + 1, INF)));
	//dp[i][j][k] ... 弁当iまで選んでたこ焼きi個,たい焼きj個を満たしている時の購入数の最小値
	for(ll i = 0; i <= n; i++)  dp[i][0][0] = 0;
	for(ll i = 0; i < n; i++) for(ll j = 0; j <= x; j++) for(ll k = 0; k <= y; k++) {
		dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
		ll jfix = min(x, j + a[i]), kfix = min(y, k + b[i]);
		dp[i + 1][jfix][kfix] = min(dp[i][j][k] + 1, dp[i + 1][jfix][kfix]);
	}
	ll ans = 0;
	if(dp[n][x][y] == INF) cout << -1 << endl;
	else cout << dp[n][x][y] << endl;
}