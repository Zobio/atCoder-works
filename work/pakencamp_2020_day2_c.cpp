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

vll ans;

void solve() {
	ll n, m; cin >> n >> m;
	if(n == 2) {
		ll cnt1 = 0, cnt2 = 0;
		rep(i, m) {
			ll a, b; cin >> a >> b; a--; b--;
			if(a == 0) cnt1++; else cnt2++;
		}
		ans.push_back(abs(cnt1 - cnt2));
	}
	else if(m <= 2) {
		if(m == 1) {ll tmp; cin >> tmp >> tmp; ans.push_back(1);}
		else {
			ll a, b, c, d; cin >> a >> b >> c >> d;
			if(b != c) ans.push_back(2);
			else if(a != d) ans.push_back(1);
			else ans.push_back(0);
		}
	}
}

int main() { //15点解答(N=2)
	ll t; cin >> t;
	rep(i, t) solve();
	for(auto au : ans) cout << au << endl;
}