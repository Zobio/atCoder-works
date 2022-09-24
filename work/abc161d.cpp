#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define reep(i, a, b) for(long long i = a; i < b; i++)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;}
#define setcout(n) cout << setprecision(n) << fixed
#define YESS {printf("Yes\n"); return 0;}
#define NOO {printf("No\n"); return 0;}
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define mint modint998244353
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll ma = 11;
	vvll dp(ma, vll(10)); //dp[i][j] : i桁で1番上の桁の数がjであるルンルン数の総数
	rep(i, 10) dp[0][i] = 1;
	rep(i, 10) rep(j, 10) {
		if(j > 0) dp[i + 1][j] += dp[i][j - 1];
		dp[i + 1][j] += dp[i][j];
		if(j < 9) dp[i + 1][j] += dp[i][j + 1];
	}
	vvll rui(ma, vll(11)); //各桁についての個数の累積和
	rep(i, ma) reps(j, 9) rui[i][j + 1] = rui[i][j] + dp[i][j];
	vll d_rui(ma + 1); //桁ごとのルンルン数の個数の累積和
	rep(i, ma) d_rui[i + 1] = d_rui[i] + rui[i].back();
	arrcout2(dp); arrcout2(rui);
	cout << endl;
	arrcout(d_rui);
	vll rui2(ma, vll(11));

	ll n; cin >> n;
	ll digit = lower_bound(all(d_rui), n) - d_rui.begin();
	ll rst = n - d_rui[digit - 1];
	ll ans = 0;
	cout << "digit: " <<  digit << endl;
	cout << "rst: " << rst << endl;
	for(ll i = digit - 1; i >= 0; i--) {
		ans *= 10;
		auto it = lower_bound(all(rui[i]), rst) - 1;
		ans += it - rui[i].begin();
		rst -= *it;
		cout << i << " " << it - rui[i].begin() - 1 << "  " << rst << endl;
	}
	cout << ans << endl;
}