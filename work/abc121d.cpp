#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007


int main() {
	ll a, b;
	cin >> a >> b;
	if(b - a == 1) {
		cout << (a ^ b) << endl;
		return 0;
	}
	else if(a == b) {
		cout << a << endl;
		return 0;
	}
	ll start, end;
	vector<ll> lst;
	for(ll i = a;; i++) {
		if(i % 2 == 0) {
			start = i;
			break;
		}else{
			lst.push_back(i);
		}
	}
	for(ll i = b;; i--) {
		if(i % 2) {
			end = i;
			break;
		}else{
			lst.push_back(i);
		}
	}
	ll ans = ((end - start + 1) / 2) % 2 ? 1 : 0;
	for(ll i = 0; i < lst.size(); i++) {
		ans ^= lst[i];
	}
	cout << ans << endl;
}