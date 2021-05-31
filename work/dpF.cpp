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
	deque<char> ans;
	int i = 0, j = 0;
	while(i < s.length() && j < t.length()) {
		if (dp[i][j] == dp[i][j + 1])j++;
		else if (dp[i][j] == dp[i + 1][j])i++;
		else {
			ans.push_front(s[i]);
			i++; j++;
		}
		cout << i << " " << j << endl;
	}
	for(int a : ans) cout << a;
	cout<< endl;
}