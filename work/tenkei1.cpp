#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

vector<ll> a;
int n; ll l, k;

bool ok(ll v) {
	ll cnt = 0;
	ll now = 0;
	ll minus = 0;
	for(int i = 0; i < n; i++) {
		if(cnt == k) break;
		if(a[i] - minus < v) {
			continue;
		}else{
			cnt++;
			minus = a[i];
		}
	}
	if(cnt == k) {
			if(l - minus >= v) return true;
			else return false;
	}
	return false;
}

int main() {
	cin >> n >> l >> k;
	a.resize(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ll left = 0, right = 1000000000, mid;
	while(right - left > 1) {
		mid = left + (right - left) / 2;
		if(ok(mid)) left = mid;
		else right = mid;
	}
	cout << left << endl;
}