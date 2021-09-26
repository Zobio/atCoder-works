#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 998244353LL
#define INF 1LL << 60

int main() {
	ll n; cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a.at(i);
	vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(10, vector<ll>(10)));
	//dp[i][j][k] ... 操作をi回した後先頭がj、その次がkになる通り数
	dp[0][a[0]][a[1]] = 1;
	for(ll i = 0; i < n - 2; i++) {
		rep(j, 10) {
			rep(k, 10) {
				dp[i + 1][(j + k) % 10][a[i + 2]] = (dp[i][j][k] + dp[i + 1][(j + k) % 10][a[i + 2]]) % MOD;
				dp[i + 1][(j * k) % 10][a[i + 2]] = (dp[i][j][k] + dp[i + 1][(j * k) % 10][a[i + 2]]) % MOD;
			}
		}
	}
	vector<ll> ans(10);
	rep(i, 10) rep(j, 10) {
		ans[(i + j) % 10] = (ans[(i + j) % 10] + dp[n - 2][i][j]) % MOD;
		ans[(i * j) % 10] = (ans[(i * j) % 10] + dp[n - 2][i][j]) % MOD;
	}
	rep(i, 10) cout << ans[i] % MOD << endl;
}