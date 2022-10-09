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
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j).val(); cout << endl;}
#define setcout(n) cout << setprecision(n) << fixed
#define YESS {printf("Yes\n"); return 0;}
#define NOO {printf("No\n"); return 0;}
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 1000000007LL
#define mint modint1000000007
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n; cin >> n;
	vll a(n); rep(i, n) cin >> a[i];
	vector<vector<mint>> dp(n , vector<mint>(2)); //dp[i][j] : i番目の数、前置の演算子が0?+:-であるときの場合の数
	vector<vector<mint>> sum(n, vector<mint>(2)); //sum[i][j] : i番目の数、前置の演算子が0?+:-であるときの式の値の合計
	dp[0][0] = 1; //初期値
	sum[0][0] = a[0]; //初期値
	rep(i, n - 1) {
		dp[i + 1][0] = dp[i][0] + dp[i][1];
		dp[i + 1][1] = dp[i][0];
		
		sum[i + 1][0] = sum[i][0] + sum[i][1] + a[i + 1] * dp[i + 1][0];
		sum[i + 1][1] = sum[i][0] - a[i + 1] * dp[i + 1][1];
	}
	cout << (sum.back().at(0).val() + sum.back().at(1).val()) % MOD << endl;
}