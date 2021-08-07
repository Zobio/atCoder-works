#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(i) cout << i << endl

int n;
ll a, b;
vector<ll> h;

bool ok(ll num) {
	ll cnt = 0;
	for(int i = 0; i < n; i++) {
		if(h[i] <= num * b) continue;
		cnt += (h[i] - num * b) / (a - b) + (ll)((h[i] - num * b) % (a - b) != 0);
	}
	if(num >= cnt) return true;
	return false;
}

int main() {
	cin >> n >> a >> b;
	h.resize(n);
	rep(i, n) cin >> h.at(i);
	sort(h.begin(), h.end());
	ll left = 0, right = 1e10;
	while(right - left > 1) {
		ll mid = (left + right) / 2;
		if(ok(mid)) right = mid;
		else left = mid;
	}
	cout << right << endl;
}