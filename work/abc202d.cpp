#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

vector<vector<ll>> dp;

string f(ll a, ll b, ll k) {
	if(a == 0) {
		string res = "";
		rep(i, b) res += 'b';
		return res;
	}
	if(b == 0) {
		string res = "";
		rep(i, a) res += 'a';
		return res;
	}
	if(k <= dp[a - 1][b]) {
		return 'a' + f(a - 1, b, k);
	}
	else{
		return 'b' + f(a, b - 1, k - dp[a - 1][b]);
	}
}

int main() {
	ll a, b, k;
	cin >> a >> b >> k;
	dp.assign(a + 1, vector<ll>(b + 1));
	dp[0][0] = 1; //dp[i][j] ... aがi個、bがj個あるときの組み合わせ総数
	rep(i, a) dp[i + 1][0] = 1;
	rep(i, b) dp[0][i + 1] = 1;
	for(ll i = 1; i <= a; i++) for(ll j = 1; j <= b; j++) {
		if(i == 0 || j == 0) {dp[i][j] = 1; continue;}
        dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
		cout << i << " " << j << " " << dp[i][j] << endl;
	}
	cout << f(a, b, k) << endl;
}