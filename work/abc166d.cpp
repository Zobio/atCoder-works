#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	ll x; cin >> x;
	map<ll, ll> mp1;
	map<ll, ll> mp2;
	mp1[0] = mp2[0] = 0;
	ll last, first;
	for(ll i = 1; i*i*i*i*i - mp1[i - 1] <= x; i++) {
		last = i;
		mp1[i] = i*i*i*i*i;
		mp2[i*i*i*i*i] = i;
	}
	for(ll i = -1; mp1[i + 1] - i*i*i*i*i <= x; i--) {
		first = i;
		mp1[i] = i*i*i*i*i;
		mp2[i*i*i*i*i] = i;
	}
	for(ll i = first; i <= last; i++) {
		if(mp2[mp1[i] + x] != 0) {
			cout << mp2[mp1[i] + x] << " " << i << endl;
			return 0;
		}
		else if (mp2[mp1[i] - x] != 0) {
			cout << i << " " << mp2[mp1[i] - x] << endl;
			return 0;
		}
	}
}