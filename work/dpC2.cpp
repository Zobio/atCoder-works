#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(a) cout << a << endl

int main() {
	int n;
	cin >> n;
	vector<vector<ll>> job(n, vector<ll>(3));
	rep(i, n) cin >> job[i][0] >> job[i][1] >> job[i][2];
	vector<vector<ll>> dp(n, vector<ll>(3));
	rep(i, 3) dp[0][i] = job[0][i];
	for(int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + job[i][0];
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + job[i][1];
		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + job[i][2];
	}
	cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl;
}