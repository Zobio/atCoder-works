#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	ll ans = 0;
	ans += a * (n / (a + b));
	if(n % (a + b) != 0) {
		ans += min(n % (a + b), a);
	}
	cout << ans << endl;
}
