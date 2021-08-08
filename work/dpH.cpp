#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(a) cout << a << endl

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<bool>> load(h, vector<bool>(w, true)); 
	rep(i,h) {
		string s;
		cin >> s;
		rep(j, w) {
			if(s[j] == '#') load[i][j] = false; 
		}
	}
	vector<vector<ll>> dp(h, vector<ll>(w, 0));
	dp[0][0] = 1;
	rep(i, h) {
		rep(j, w) {
			if(i != 0 && j != 0) dp[i][j] = (load[i - 1][j] ? dp[i - 1][j] : 0) + (load[i][j - 1] ? dp[i][j - 1] : 0);
			else if(i == 0 && j != 0) dp[i][j] = load[i][j - 1] ? dp[i][j - 1] : 0;
			else if(i != 0 && j == 0) dp[i][j] = load[i - 1][j] ? dp[i - 1][j] : 0;
			dp[i][j] %= MOD;
		}
	}
	cout << dp[h - 1][w - 1] << endl;
}