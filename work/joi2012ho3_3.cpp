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

int main() {
	ll n, t, s; cin >> n >> t >> s;
	vpll shop(n); rep(i, n) cin >> shop[i].first >> shop[i].second; //firstが楽しさ secondが時間
	vvll dp1(n + 1, vll(s + 1)); //dp1[i][j]...時刻jまでに0~i番目の夜店までを見たときの楽しさの合計値の最大値
	vvll dp2(n + 1, vll(t - s + 1)); //dp2[i][j]...時刻s + jまでにn-1 ~ n-1 - i番目の夜店までを見たときの楽しさの合計値の最大値
	rep(i, n) rep(j, s + 1) {
		ll fun = shop[i].first, time = shop[i].second;
		chmax(dp1[i + 1][j], dp1[i][j]);
		if(j + time <= s) chmax(dp1[i + 1][j + time], dp1[i][j] + fun);
	}
	rreps(i, n) rep(j, t - s + 1) {
		ll fun = shop[i - 1].first, time = shop[i - 1].second;
		chmax(dp2[i - 1][j], dp2[i][j]);
		if(j + time <= t - s) chmax(dp2[i - 1][j + time], dp2[i][j] + fun);
	}
	ll ans = 0;
	rep(i, n) chmax(ans, dp1[i + 1].back() + dp2[i + 1].back()); //(時刻sまでの)0~i番目までの最大値と(時刻sからの)i+1 ~ n-1番目までの最大値のmaxが答え
	cout << ans << endl;
}