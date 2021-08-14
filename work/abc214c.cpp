#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	ll sumS = 0;
	pair<int, ll> firstT = make_pair(-1, 1e9 + 7);
	vector<ll> s(n); rep(i, n) cin >> s[i], sumS += s[i];
	vector<ll> t(n); rep(i, n) {cin >> t[i]; if(firstT.second > t[i]) firstT = make_pair(i, t[i]);}
	vector<ll> dp(n);
	dp[firstT.first] = firstT.second;
	for(int i = 1; i < n; i++) {
		int now = (firstT.first + i) % n;
		dp[now] = min(t[now], dp[(now - 1 + n) % n] + s[(now - 1 + n) % n]);
	}
	rep(i, n) cout << dp[i] << endl;
}