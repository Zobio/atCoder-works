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
	vector<ll> h(n);
	rep(i, n) cin >> h.at(i);
	vector<ll> dp(n + 1);
	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);
	rep(i, n - 1) {
		dp[i + 2] = min((dp[i + 1] + abs(h[i + 2] - h[i + 1])), (dp[i] + abs(h[i + 2] - h[i])));
	}
	cout << dp[n - 1] << endl;
}