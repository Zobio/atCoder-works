#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n; cin >> n;
	ll k; cin >> k;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	vector<ll> aCp = a;
	sort(aCp.begin(), aCp.end());
	ll rest = k - ((k / n) * n);
	ll lim = -1;
	if(k % n != 0)
	lim = aCp[rest - 1];
	vector<ll> ans(n);
	for(int i = 0; i < n; i++) {
		ans[i] += k / n;
		if(a[i] <= lim & lim != -1) ans[i]++;
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}
}