#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

ll mpow(ll a, ll b) {
	if(a == 1) return 1;
	ll res = 1;
	rep(i, b) {
		res = (res * a) % MOD;
	}
	return res;
}

int main() {
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	for(ll i = 1; i <= sqrt(k) + 1; i++) {
		ans = (ans + mpow(k / i, n)) % MOD;
	}
	cout << ans << endl;
}