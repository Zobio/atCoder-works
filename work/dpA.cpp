#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for(int i = 0; i < n; i++) {
		cin >> h[i];
	}
	vector<int> dp(n);
	for(int i = 1; i < n; i++) {
		if (i == 1) {
			dp[i] = abs(h[i] - h[i - 1]);
		}else{
			dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
		}
	}
	cout << dp[n - 1] << endl;
}