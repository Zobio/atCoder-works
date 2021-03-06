#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, q;
	cin >> n;
	vector<ll> a(1001, 0);
	for(int i = 0; i < n; i++) {
		cin >> q;
		q += 200;
		a[q]++;
	}
	ll ans = 0;
	for(int i = 0; i <= 400; i++) {
		for(int j = i + 1; j <= 400; j++) {
			ans += (ll)((j - i) * (j - i) * a[i] * a[j]);
		}
	}
	cout << ans << endl;
}