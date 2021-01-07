#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int leng = s.length();
	vector<vector<long long>> dp(leng + 1, vector<long long>(13));
	vector<int> num(leng);
	for(int i = 0; i < leng; i++) {
		if(s[i] == '?') {
			num[i] = -1;
		}else{
			num[i] = s[i] - '0';
		}
	}
	dp[0][0] = 1;
	for(int i = 0; i < leng; i++) {
		for(int j = 0; j < 10; j++) {
			if(num[i] != -1 && num[i] != j)continue;
			for(int ki = 0; ki < 13; ki++) {
				dp[i + 1][(ki * 10 + j) % 13] += dp[i][ki];
				cout << "dp[" << i + 1 << "][" << (ki * 10 + j) % 13 << "(" << ki * 10 + j << ")]: " << dp[i + 1][(ki * 10 + j) % 13] << endl;
			}
		}
		for (int j = 0; j < 13; j++) dp[i + 1][j] %= 1000000007;
	}
	cout << dp[leng][5] << endl;
}