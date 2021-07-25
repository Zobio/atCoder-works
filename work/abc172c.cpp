#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m;
	cin >> n >> m;
	ll k;
	cin >> k;
	vector<ll> a(n);
	vector<ll> b(m);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	vector<ll> ra(n + 1);
	for(int i = 0; i < n; i++) ra[i + 1] = ra[i] + a[i];
	vector<ll> rb(m + 1);
	for(int i = 0; i < m; i++) rb[i + 1] = rb[i] + b[i];
	int ans = 0;
	int ok = m;
	for(int i = 0; i < n + 1; i++) {
		while (0 <= ok && k < ra[i] + rb[ok]) ok--;
		if(0 <= ok) ans = max(ans, i + ok);
	}
	cout << ans << endl;
}