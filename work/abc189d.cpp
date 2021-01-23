#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string next;
	vector<long long> dp(n + 1);
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		cin >> next;
		if(next == "AND") {
			dp[i] = dp[i - 1];
		}else{
			dp[i] = (1LL << i) + dp[i - 1];
		}
	}
	cout << dp[n] << endl;
}