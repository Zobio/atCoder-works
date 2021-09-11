#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	ll n; cin >> n;
	map<pair<ll, ll>, ll> mp;
	map<tuple<pair<ll, ll>, pair<ll, ll>, pair<ll, ll>, pair<ll, ll>>, bool> done; 
	rep(i, n) {
		ll a, b; cin >> a >> b;
		mp[make_pair(a, b)]++;
	}
	ll ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++) {
 		for(auto jt = it; jt != mp.end(); jt++) {
			if(jt == it) jt++;
			if(jt == mp.end()) break;
			ll a = it -> first.first, b = it -> first.second, c = jt -> first.first, d = jt -> first.second;
			if (mp[make_pair(a, d)] && mp[make_pair(c, b)] && !done[make_tuple(make_pair(a, b), make_pair(c, d), make_pair(a, d), make_pair(c, b))]) {
				ans += min(min(min(mp[make_pair(a, b)], mp[make_pair(c, d)]), mp[make_pair(c, b)]), mp[make_pair(a, d)]);
				vector<pair<ll, ll>> perm = {make_pair(a, b), make_pair(c, d), make_pair(a, d), make_pair(c, b)};
				sort(perm.begin(), perm.end());
				do{
					done[make_tuple(perm[0], perm[1], perm[2], perm[3])] = true;
				}while(next_permutation(perm.begin(), perm.end()));
			}
		}
	}
	cout << ans << endl;
}