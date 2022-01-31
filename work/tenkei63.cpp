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
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll calc_max(vll a) {
	map<ll, ll> mp;
	ll ret = 0;
	for(auto au : a) mp[au]++, chmax(ret, mp[au]);
	return ret;
}

int main() {
	ll h, w; cin >> h >> w;
	vvll p(h, vll(w));
	rep(i, h) rep(j, w) cin >> p[i][j];
	ll ans = 0;
	rep(bits, 1ll << h) {
		vll r;
		rep(j, w) {
			ll id = -1, flag = true;
			rep(k, h) {
				if(!(bits & (1 << k))) continue;
				if(id == -1) id = p[k][j];
				else if(id != p[k][j]) flag = false;
			}
			if(flag) r.push_back(id);
		}
		ll cntW = calc_max(r);
		ll cntH = 0; rep(k, h) if(bits & (1 << k)) cntH++;
		chmax(ans, cntW * cntH);
	}
	cout << ans << endl;
}