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
	map<ll, ll> mp;
	ll sum = 0;
	rep(i, n) {
		ll a; cin >> a;
		mp[a]++;
		sum += a;
	}
	ll q; cin >> q;
	vector<pair<ll, ll>> bc;
	rep(i, q) {
		ll b, c; cin >> b >> c;
		bc.push_back(make_pair(b, c));
	}
	rep(i, q) {
		sum += mp[bc[i].first] * (bc[i].second - bc[i].first);
		cout << sum << endl;
		mp[bc[i].second] += mp[bc[i].first];
		mp[bc[i].first] = 0;
	}
}