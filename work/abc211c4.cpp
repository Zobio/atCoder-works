#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> dp(9);
	dp[0] = 1;
	string t = "chokudai";
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 8; j++) {
			if(s[i] == t[j]){
				dp[j + 1] = (dp[j + 1] + dp[j]) % MOD;
				//cout << j + 1 << " " << dp[j + 1] << endl;
			}
		}
	}
	cout << dp[8] << endl;
}