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

int main() {
	ll n, m; cin >> n >> m;
	vpll a(n), c(n);
	rep(i, m) {ll p, q; cin >> p >> q; p--; q--; a[i] = {p, q};}
	rep(i, m) {ll p, q; cin >> p >> q; p--; q--; c[i] = {p, q};}
	sort(all(a)); sort(all(c));
	rep(_, n) {
		vvll ga(n), gc(n);
		rep(i, a.size()) {
			ga[a[i].first].push_back(a[i].second);
			ga[a[i].second].push_back(a[i].first);
		}
		rep(i, c.size()) {
			ga[c[i].first].push_back(c[i].second);
			ga[c[i].second].push_back(c[i].first);
		}
		rep(i, n) sort(all(ga[i])), sort(all(gc[i]));
		rep(i, n) {for(ll j : ga[i]) cout << j << " "; cout << endl;}
		rep(i, n) {for(ll j : gc[i]) cout << j << " "; cout << endl;}
		bool flag = true;
		rep(i, n) {
			if(ga[i].size() != gc[i].size()) {flag = false; break;}//breakしないと下のループでRE
			rep(j, ga[i].size()) if(ga[i][j] != gc[i][j]) flag = false;
		}
		if(flag) {cout << "Yes" << endl; return 0;}
		rep(i, m) {
			a[i].first = (a[i].first + 1) % n;
			a[i].second = (a[i].second + 1) % n;
			c[i].first = (c[i].first + 1) % n;
			c[i].second = (c[i].second + 1) % n;
		}
	}
	cout << "No" << endl;
}