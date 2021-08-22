#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	map<char, int> mp; mp['c'] = 1; mp['h'] = 2; mp['o'] = 3; mp['k'] = 4; mp['u'] = 5; mp['d'] = 6; mp['a'] = 7; mp['i'] = 8;
	string s; cin >> s;
	vector<int> ss (s.size());
	rep(i, s.size()) ss.at(i) = mp[s[i]];
	vector<vector<ll>> dp(s.size() + 1, vector<ll>(9));
	rep(i, dp.size()) dp[i][0] = 1;
	rep(i, 8) dp[0][i + 1] = 0;
	for(int i = 1; i < dp.size(); i++) {
		for(int j = 1; j <= 8; j++) {
			if(ss[i - 1] == j) dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[ss.size()][8] << endl;
}