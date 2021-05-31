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
	string ans = "";
	int len = dp[s.length()][t.length()];
	int slen = s.length(), tlen = t.length();
	while(len + 1) {
		cout << slen << " " << s[slen] << " " << tlen << " " << t[tlen] << endl;
		if(s[slen] == t[tlen]) {
			ans += s[slen];
			slen--;
			tlen--;
			len--;
			cout << "len: " << len << endl;
		}
		else if(dp[slen][tlen] == dp[slen - 1][tlen] && slen - 1 >= 0) {
			slen--;
		}else{
			tlen--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}