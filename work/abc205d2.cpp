#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	vector<ll> k(q);
	rep(i, n) cin >> a.at(i), a[i] -= i + 1;
	while(q--) {
		ll k; cin >> k;
		cout << k << " " << (lower_bound(a.begin(), a.end(), k) - a.begin()) << endl;
		cout << k + (lower_bound(a.begin(), a.end(), k) - a.begin()) << endl;
	}
}