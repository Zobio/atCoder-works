#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	rep(i, n) cin >> a[i], sum += a[i];
	ll ans = 0;
	rep(i, n) {
		sum -= a[i];
		ans = (ans + a[i] * (sum % MOD)) % MOD;
	}
	cout << ans  << endl;
}