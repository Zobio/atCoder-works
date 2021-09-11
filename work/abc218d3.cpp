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
	vector<pair<ll, ll>> vp(n);
	rep(i, n) cin >> vp[i].first >> vp[i].second;
	sort(vp.begin(), vp.end());
	ll ans = 0;
	rep(i, n) rep(j, n) {
		if(vp[i].first < vp[j].first && vp[i].second < vp[j].second) {
			ll a = vp[i].first, b = vp[i].second, c = vp[j].first, d = vp[j].second;
			ans += binary_search(vp.begin(), vp.end(), make_pair(c, b)) && binary_search(vp.begin(), vp.end(), make_pair(a, d));
		}
	}
	cout << ans << endl;
}