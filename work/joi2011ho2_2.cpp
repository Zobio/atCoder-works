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
	ll n, k; cin >> n >> k;
	vvll g(10);
	rep(i, n) {
		ll a, b; cin >> a >> b; b--; g[b].push_back(a);
	}
	rep(i, 10) sort(rall(g[i]));
	vvll dp(11, vll(k + 1)); //dp[i][j] : i番目までのカテゴリーからj個売った時の儲けの最大値
	rep(i, 10) {
		rep(j, min((ll)g[i].size(), k)) {
			chmax(dp[i + 1][j + 1], dp[i][j + 1] + j * (j + 1));
			chmax(dp[i + 1][j + 1], dp[i][j] + g[i][j] + j * (j + 1));
		}
	}
	reps(i, 10) {reps(j, k) cout << dp[i][j] << " "; cout << endl;}
	cout << dp[9][k] << endl;
}