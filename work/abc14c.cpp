#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(a) cout << a << endl

int main() {
	int n;
	cin >> n;
	vector<ll> cl(1000001);
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		cl[a]++;
		cl[++b]--;
	}
	ll ans = 0;
	ll now = 0;
	rep(i, 1000001) {
		now += cl[i];
		ans = max(ans, now);
	}
	cout << ans << endl;
}