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
	ll m, n; cin >> m >> n; //mは饅頭、nは箱の数
	vll p(m); rep(i, m) cin >> p[i];
	sort(rall(p));
	vll rui(m + 1); rep(i, m) rui[i + 1] = rui[i] + p[i];
	vpll box(n); rep(i, n) cin >> box[i].first >> box[i].second; //first: 値段 second:大きさ
	vvll dp(n + 1, vll(m + 1, INF)); //dp[i][j]...i番目の箱までを見てj個の饅頭を入れるときの箱のコストの最小値
	rep(i, n + 1) dp[i][0] = 0;
	rep(i, n) rep(j, m + 1) {
		ll cost = box[i].second, use = box[i].first;
		chmin(dp[i + 1][j], dp[i][j]);
		chmin(dp[i + 1][min(m, j + use)], dp[i][j] + cost);
	}
	ll ans = 0;
	reps(i, m) chmax(ans, rui[i] - dp[n][i]);
	cout << ans << endl;
}