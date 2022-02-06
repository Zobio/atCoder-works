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
	ll n; cin >> n;
	vll a(n); rep(i, n) cin >> a[i];
	vll b(n - 1); rep(i, n - 1) b[i] = a[i + 1] - a[i]; //階差数列
	vll cost_up(n - 1), cost_down(n - 1);
	rep(i, n - 1) {
		if(b[i] <= 0) cost_up[i] = 1 + abs(b[i]);
		if(b[i] >= 0) cost_down[i] = 1 + abs(b[i]);
	}
	vll rui_up(n), rui_down(n);
	rep(i, n - 1) rui_up[i + 1] = rui_up[i] + cost_up[i];
	rep(i, n - 1) rui_down[i + 1] = rui_down[i] + cost_down[i];
	ll ans = INF;
	rep(i, n) {
		chmin(ans, max(rui_up[i],  rui_down[n - 1] - rui_down[i]));
	}
	cout << ans << endl;
}