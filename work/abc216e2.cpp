#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	ll n, k; cin >> n >> k;
	vector<ll> a(n); rep(i, n) cin >> a.at(i);
	sort(a.begin(), a.end());
	ll ng = -1, ok = 2000000010;
	while(ok - ng > 1) {
		ll mid = (ng + ok) / 2;
		ll tmp = 0;
		rep(i, n) tmp += max(0ll, a[i] - mid + 1);
		if(tmp < k) ok = mid;
		else ng = mid;
	}
	ll ans = 0;
	if(ok == 0) {
		rep(i, n) ans += a[i] * (a[i] + 1) / 2;
		cout << ans << endl; return 0;
	}
	rep(i, n) {
		if(a[i] < ok) continue;
		ll L = a[i];
		ll A = ok;
		ll N = L - A + 1;
		ans += N * (A + L) / 2;
		k -= N;
	}
	ans += k * (ok - 1);
	cout << ans << endl;
}