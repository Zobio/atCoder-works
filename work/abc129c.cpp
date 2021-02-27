#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m;
	cin >> n >> m;
	vector<bool> oks(n + 1, true);
	for(int i = 0; i < m; i++) {
		int a;
		cin>>a;
		oks[a] = false;
	}
	vector<ll> dp(n + 1);
	dp[0] = 1;
	for(int now = 0; now < n; now++) {
		for(int next = now + 1; next <= min(n, now + 2); next++) {
			if(oks[next]) {
				dp[next] += dp[now];
				dp[next] %= MOD;
			}
		}
	}
	cout << dp[n] << endl;
}