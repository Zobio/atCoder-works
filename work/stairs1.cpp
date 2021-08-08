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
	vector<ll> dp(n + 1);
	dp[0] = dp[1] = 1;
	for(int i = 0; i < n - 1; i++) {
		dp[i + 2] = dp[i] + dp[i + 1];
	}
	cout << dp[n] << endl;
}