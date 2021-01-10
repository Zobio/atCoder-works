#include<bits/stdc++.h>
using namespace std;
#define INF 922337203685477580

int main() {
	int N,W;
	cin >> N >> W;
	vector<long long> w(N);
	vector<long long> v(N);
	for(int i = 0; i < N; i++) {
		cin >> w[i] >> v[i];
	}
	vector<vector<long long>> dp(N, vector<long long>(100001, INF));
	dp[0][0] = 0;
	for(int i = 1; i <= v[0]; i++) {
		dp[0][i] = w[0];
	}
	for(int i = 1; i < N; i++) {
		for(int j = 0; j <= 100000; j++) {
			if(j - v[i] < 0) {
				dp[i][j] = dp[i - 1][j];
			}else{
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
			}
		}
	}
	int ans = 100000;
	while(dp[N - 1][ans] > W){ 
	
		ans--;
		}
	cout << ans << endl;
}