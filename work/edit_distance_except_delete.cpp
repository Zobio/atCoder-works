#include <bits/stdc++.h>
using namespace std;

constexpr int INSERT_COST = 1;
constexpr int DELETE_COST = 1;
constexpr int CHANGE_COST = 1;

int main() {
	string x, y; cin >> x >> y;
	string z;
	int n = x.size();
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1000000000));
	for(int i = 0; i <= n; i++) dp[0][i] = dp[i][0] = i;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int D = dp[i][j + 1] + DELETE_COST;
			int I = dp[i + 1][j] + INSERT_COST;
			int C = dp[i][j] + (x[i] == y[j] ? 0 : CHANGE_COST);
			if(D < I && D < C) 
			dp[i + 1][j + 1] = min({D, I, C});
		}
	}
	cout << dp[n][n] << endl;
}