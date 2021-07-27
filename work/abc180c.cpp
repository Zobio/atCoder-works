#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ll a1 = 0, a2 = 0, a3 = 0;
	for(int i = 0; i < n; i++) {
		a1 += abs(a[i]);
		a2 += a[i] * a[i];
		a3 = max(a3, abs(a[i]));
	}
	cout << a1 << endl;
	cout << /*setprecision(16) << fixed <<*/ (double)(sqrt(a2)) << endl;
	cout << a3 << endl;
}