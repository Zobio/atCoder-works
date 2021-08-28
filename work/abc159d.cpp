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
	vector<ll> a(n);
	map<ll, ll> mp;
	rep(i, n) {
		cin >> a.at(i);
		a[i]--;
		mp[a[i]]++;
	}
	ll sum = 0;
	rep(i, n) sum += mp[i] * (mp[i] - 1) / 2;
	rep(i, n) {
		ll now = a[i];
		cout << sum - mp[now] * (mp[now] - 1) / 2 + (mp[now] - 1) * (mp[now] - 2) / 2 << endl;
	}
}