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

bool comp(const pll a, const pll b) {
	return a.second < b.second;
}

int main() {
	ll n, t, s; cin >> n >> t >> s;
	vpll shop(n); rep(i, n) cin >> shop[i].first >> shop[i].second; //firstが楽しさ secondが時間
	sort(all(shop), comp);
	vvll dp(n + 1, vll(t + 1)); //dp[i][j]...i番目の店までを時刻jまでで見たときの楽しさの合計値の最大値(∴答えはdp[t][n-1])
	rep(i, n) rep(j, t + 1) {
		ll fun = shop[i].first, time = shop[i].second;
		if(j == 0) cout << fun << " " << time << endl;
		if((j <= s) == (j - time <= s) && j - time >= 0) dp[i + 1][j] =  max(dp[i][j - time] + fun, dp[i][j]);
		else dp[i + 1][j] = dp[i][j];
		if(j) chmax(dp[i + 1][j], dp[i + 1][j - 1]);
	}
	rep(i, dp.size()) {rep(j, dp[i].size()) cout << dp[i][j] << (j == s ? "  " : " "); cout << endl;}
	cout << dp[n][t] << endl;
}