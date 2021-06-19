#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ll l, r;
	cin >> l >> r;
	ull ans = 0;
	for(ll a = 2; a <= r / 2; a++) {
		ll div = r / a - l / a + (!(l & 1) && !(r & 1) ? 1 : 0);
		//cout << "div: " << div << endl;
		ans += max((ll)0, div * (div - 1));
		//cout << "a: " << a << " " << ans << endl;
	}
	cout << ans << endl;
}