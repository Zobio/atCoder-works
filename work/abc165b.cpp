#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ull x;
	cin >> x;
	if(x <= 100.0) {
		cout << 0 << endl;
		return 0;
	}
	ull now = 100;
	ll ans = 0;
	while(true) {
		ans++;
		now += now / 100;
		if(x <= now) break;
	}
	cout << ans << endl;
}