#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int s, t;
	cin >> s >> t;
	ll ans = 0;
	rep(a, 101) {
		rep(b, 101) {
			rep(c, 101) {
				if(a + b + c <= s && a * b * c <= t) ans++;
			}
		}
	}
	cout << ans << endl;
}