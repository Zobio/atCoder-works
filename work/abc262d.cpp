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
#define arrcout3(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) {for(size_t k = 0; k < a[i][j].size(); k++) cout << (k ? " " : "") << a.at(i).at(j).at(k); cout << endl;} cout << endl;}
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define mint modint998244353
#define INF (1LL << 60)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n; cin >> n;
	vll a(n); rep(i, n) cin >> a[i];
	mint ans = 0;
	reps(i, n) {
		vector<vector<vector<mint>>> dp(n + 1, vector<vector<mint>>(i + 1, vector<mint>(i))); // dp[j][k][l] : [a_0, a_j]からk個選んで(総和) % p == lとなる個数
		dp[0][0][0] = 1;
		rep(j, n) for(ll k = 0; k <= i; k++) rep(l, i) {
			dp[j + 1][k][l] += dp[j][k][l]; //選ばない
			if(k < i) dp[j + 1][k + 1][(l + a[j]) % i] += dp[j][k][l]; //選ぶ
		}
		ans += dp[n][i][0];
	}
	cout << ans.val() << endl;
}