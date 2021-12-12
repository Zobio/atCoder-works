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

int main() { //priority_queue? dp?
	ll n, k; cin >> n >> k;
	vll a(n); rep(i, n) cin >> a[i];
	vvll dp(n + 1, vll(n + 1));//dp[i][j] : i個目とi - j個目のアメを選んだ時の美味しさの合計値の最大値(∴ans=max(dp[n][(n - k) ~ n]))
	vll ma(n + 1); //各dpの最大値
	reps(i, n) {
		for(ll j = max(0ll, i - k); j <= i; j++) {
			if(j == 0) dp.at(i).at(j) = a.at(i - 1);
			else dp.at(i).at(j) = ma.at(min(j - 1, i - k)) + a.at(i - 1) + a.at(j - 1);
		}
		rep(j, i + 1) if(chmax(ma.at(i), dp.at(i).at(j))) ma.at(i) = i, ma.at(i) = j;
		chmax(ma[i], ma[i - 1]);
	}
	ll ans = 0;
	reps(i, n) chmax(ans, ma[i]);
	cout << ans << endl;
}