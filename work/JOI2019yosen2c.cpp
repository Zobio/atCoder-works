#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(a) cout << a << endl

int main() {
	int n;
	cin >> n;
	vector<ll> dp(2000000, 1);
	for(ll i = 1; i <= n; i++) {
		ll pl = i;
		ll cp = i;
		while(cp) pl += cp % 10, cp /= 10;
		if(pl <= 1000000) dp[pl] += dp[i];
	}
	cout << dp[n] << endl;
}