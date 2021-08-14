#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<pair<ll, ll>> b(n);
	vector<ll> bb(n);
	vector<ll> c(n);
	rep(i, n) cin >> a[i];
	rep(i, n) {ll tmp; cin >> tmp; b[i] = make_pair(tmp, -1); bb[i] = tmp;}
	rep(i, n) cin >> c[i];
	sort(a.begin(), a.end()); sort(b.begin(), b.end()); sort(c.begin(), c.end()); sort(bb.begin(), bb.end());
	rep(i, n) {
		b[i].second = n - (upper_bound(c.begin(), c.end(), b[i].first) - c.begin());
	}
	vector<ll> ruiB(n + 1, 0);
	for(int i = n - 1; i >= 0; i--) ruiB[i] += ruiB[i + 1] + b[i].second;
	ll ans = 0;
	rep(i, n) {
		ans += ruiB[upper_bound(bb.begin(), bb.end(), a[i]) - bb.begin()];
	}
	cout << ans << endl;
}