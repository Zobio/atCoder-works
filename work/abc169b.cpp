#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<ull> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	if(a[0] == 0) {
		cout << 0 << endl;
		return 0;
	}
	ull ans = 1;
	rep(i, n) {
		if(log10(ans) + log10(a[i]) > 18.0) {
			cout << -1 << endl;
			return 0;
		}
		ans *= a[i];
		if(ans > 1000000000000000000) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
}