#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for(int i = 0; i < n; i++) {
		cin >> h[i];
	}
	vector<int> dp(n);
	for(int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
		for(int j = 2; j <= k; j++) {
			if(i - j >= 0) {
				dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
			}
		}
	}
	cout << dp[n - 1] << endl;
}