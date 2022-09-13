#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define vll vector<ll>

int main() {
	vll a(3), b(3); rep(i, 3) cin >> a[i] >> b[i];
	ll p = 0, q = 0;
	rep(i, 3) {
		ll t = (b[i] - a[i] + 6) % 3;
		if(t == 1) p++;
		else if(t == 2) q++;
	}
	if(p == q) cout << -1 << endl;
	else if(p < q) cout << 1 << endl;
	else cout << 0 << endl;
}