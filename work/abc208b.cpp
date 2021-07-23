#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

ll jun(ll n) {
	ll re = 1;
	for(ll i = n; i >= 1; i--) {
		re *= i;
	}
	return re;
}

int main() {
	ll p;
	cin >> p;
	vector<pair<ll, ll>> coin;
	coin.push_back(make_pair(0, 0));
	for(ll i = 1;;i++) {
		if(jun(i) > 10000000) break;
		coin.push_back(make_pair(jun(i), 100));
	}
	ll cnt = 0;
	while(p) {
		for(int i = coin.size() - 1; i >= 1; i--) {
			if(p >= coin[i].first && coin[i].second) {
				p -= coin[i].first; coin[i].second--; cnt++; break;
			}
		}
	}
	cout << cnt << endl;
}