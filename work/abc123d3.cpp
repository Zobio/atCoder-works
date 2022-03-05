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
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll x, y, z, k;
vll a, b, c;
vll bc;

bool check(ll p) {
	ll cnt = 0;
	rep(i, x) {
		ll id = lower_bound(all(bc), p - a[i]) - bc.begin();
		cnt += bc.size() - id;
	}
	return k <= cnt;
}

int main() {
	cin >> x >> y >> z >> k;
	a.resize(x); b.resize(y); c.resize(z);
	rep(i, x) cin >> a[i]; rep(i, y) cin >> b[i]; rep(i, z) cin >> c[i];
	rep(i, y) rep(j, z) bc.push_back(b[i] + c[j]);
	sort(all(bc));
	ll ok = 0, ng = INF; //美味しさの合計がok以上の個数がk以上か
	while(ng - ok > 1) {
		ll mid = (ng + ok) / 2;
		if (check(mid)) ok = mid;
		else ng = mid;
	}
	vll ans;
	sort(rall(bc));
	rep(i, x) rep(j, bc.size()) {
		if(a[i] + bc[j] >= ok) ans.push_back(a[i] + bc[j]);
		else break;
	}
	sort(rall(ans));
	rep(i, k) cout << ans[i] << endl;
}