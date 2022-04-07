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

int main() {
	ll n, m; cin >> n >> m;
	vll a(n), b(m);
	rep(i, n) cin >> a[i]; rep(i, m) cin >> b[i];
	ll sa = accumulate(all(a), 0ll), sb = accumulate(all(b), 0ll);
	if(sa == n && sb != m) {cout << -1 << endl; return 0;}
	if(sa == 0 && sb != 0) {cout << -1 << endl; return 0;} //コーナーケース
	ll cnt = INF, ans = -1;
	if(sb == 0 || sb == m) {
		rep(i, n) if(a[i] == b[0]) chmin(cnt, min(i, n - i));
		ans = cnt + m; //移動にcnt回、値の追加にm回
	}else{
		vll c = {a[0]};
		for(ll i = n - 1; i > 0; i--) c.push_back(a[i]);
		rep(i, n - 1) if(a[i] == b[0] && a[i + 1] != b[0]) chmin(cnt, i);
		rep(i, n - 1) if(c[i] == b[0] && c[i + 1] != b[0]) chmin(cnt, i);
		ans = cnt;
		ll now = b[0];
		rep(i, m) {
			if(b[0] != b[i]) b[0] = b[i], ans++;
			ans++;
		}
	}
	cout << ans << endl;
}