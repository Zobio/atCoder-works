#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ll n, k;
	cin >> n >> k;
	ll opt = n - k + 1;
	vector<vector<ll>> comb(2010, vector<ll>(2010));
	rep(i, 2010) comb[i][0] = 1;
	for(int i = 1; i < 2010; i++) for(int j = 1; j <= i; j++) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD/*, cout << i << " " << j << " " << comb[i][j] << endl*/;
	for(ll i = 1; i <= k; i++) {
		ll ans = comb[opt][i] * comb[k - 1][i - 1]% MOD; //仕切りの分け方 * ボールの分け方(k個のボールの間(k - 1)に仕切りをi - 1個おく)
		cout << ans << endl;
	}
}