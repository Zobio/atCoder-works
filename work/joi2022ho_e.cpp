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

int main() { //9点解法
	ll h, w; cin >> h >> w;
	vll a(w); rep(i, w) cin >> a[i];
	vll dp(w + 1);
	reps(i, w - 1) {
		if(a[i] > a[i - 1]) dp[i + 1] = dp[i] + 1;
		else dp[i + 1] = 0;
	}
	dp.push_back(0); //末端処理
	vll dp2(w + 2);
	rreps(i, w - 1) {
		if(a[i - 1] > a[i]) dp2[i] = dp2[i + 1] + 1;
		else dp2[i] = 0;
	}
	ll ans = w;
	rep(i, dp.size() - 1) {
		if(dp[i] > dp[i + 1]) ans += dp[i] * (dp[i] + 1) / 2;
	}
	rreps(i, dp2.size() - 1) {
		if(dp2[i] > dp2[i - 1]) ans += dp2[i] * (dp2[i] + 1) / 2;
	}
	cout << ans << endl;
}