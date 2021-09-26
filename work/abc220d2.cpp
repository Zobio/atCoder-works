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
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a.at(i);
	vector<vector<ll>> dp(n, vector<ll>(10)); //dp[i][j] ... i回操作を行って先頭がjである通り数
	dp[0][a[0]] = 1;
	rep(i, n - 1) {
		rep(j, 10) {
			dp[i + 1][(j + a[i + 1]) % 10] = (dp[i + 1][(j + a[i + 1]) % 10] + dp[i][j]) % MOD;
			dp[i + 1][(j * a[i + 1]) % 10] = (dp[i + 1][(j * a[i + 1]) % 10] + dp[i][j]) % MOD;
		}
	}
	rep(i, 10) cout << dp[n - 1][i] << endl;
}