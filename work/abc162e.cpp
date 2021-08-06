#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(i) cout << i << endl 

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
	vector<ll> cnt(k + 1, 1);
	for(int i = k; i >= 1; i--) {
		cnt[i] = mpow(k / i, n);
		int fix = i * 2;
		while(fix <= k) {
			cnt[i] -= cnt[fix];
			fix += i;
		}
	}
	for(int i = 1; i <= k; i++) ans = (ans + i * cnt[i]) % MOD;
	cout << ans << endl;
}