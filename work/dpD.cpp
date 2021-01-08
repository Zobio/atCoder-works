#include<bits/stdc++.h>
using namespace std;

int main() {
	int N,W;
	cin >> N >> W;
	vector<int> w(N);
	vector<int> v(W);
	for(int i = 0; i < N; i++) {
		cin >> w[i] >> v[i];
	}
	vector<vector<long long>> dp(N, vector<long long>(W + 1));
	for(int i = 0; i < N; i++) { //番目
		if(i == 0) {
			for(int j = w[0]; j <= W; j++) {
				dp[i][j] += v[i];
			}
			continue;
		}
		for(int j = 0; j <= W; j++) { //重さ
			if(j - w[i] < 0) {
				dp[i][j] = dp[i - 1][j];
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	cout << dp[N - 1][W] << endl;
}