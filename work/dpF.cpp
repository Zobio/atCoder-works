#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1));
	for(int i = 0; i < s.length(); i++) {
		for(int j = 0; j < t.length(); j++) {
			if(s[i] == t[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}else{
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	for(int i = 0; i <= s.length(); i++) {
		for(int j = 0; j <= t.length(); j++) {
			cout << dp[i][j];
		}
		cout << endl;
	}
	string ans;
	int i = s.length(), j = t.length();
	s = "*" + s; t = "*" + t;
	while(i > 0 && j > 0) {
		// (i-1, j) -> (i, j) と更新されていた場合
		if (dp[i][j] == dp[i - 1][j])
		{
			--i; // DP の遷移を遡る
		}

		// (i, j-1) -> (i, j) と更新されていた場合
		else if (dp[i][j] == dp[i][j - 1])
		{
			--j; // DP の遷移を遡る
		}

		// (i-1, j-1) -> (i, j) と更新されていた場合
		else
		{
			ans = s[i - 1] + ans; // このとき s[i-1] == t[j-1] なので、t[j-1] + res でも OK
			--i, --j;			  // DP の遷移を遡る
		}
		cout << i << " " << j << endl;
	}
	cout << ans << endl;
}