#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {//mapでの解答(TLE)
	ll n; cin >> n;
	vpll cor(n); map<pair<ll, ll>, ll> mp;
	rep(i, n) {
		ll x, y; cin >> x >> y;
		cor[i] = {x, y}; mp[{x, y}]++;
	}
	sort(all(cor));
	ll ans = 0;
	rep(i, n) for(ll j = i + 1; j < n; j++) {
		ll a1 = cor[i].first, a2 = cor[i].second, b1 = cor[j].first, b2 = cor[j].second;
		ll dx = a1 - b1, dy = a2 - b2;
		if(mp.find(make_pair(a1 + dy, a2 - dx)) != mp.end() && mp.find(make_pair(b1 + dy, b2 - dx)) != mp.end()) chmax(ans, dx * dx + dy * dy);
		else if(mp.find(make_pair(a1 - dy, a2 + dx)) != mp.end() && mp.find(make_pair(b1 - dy, b2 + dx)) != mp.end()) chmax(ans, dx * dx + dy * dy);
	}
	cout << ans << endl;
}