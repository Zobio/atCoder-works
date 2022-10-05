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
	//DP 経路復元
	ll n, s; cin >> n >> s;
	vll a(n), b(n); rep(i, n) cin >> a[i] >> b[i];
	vvll dp(n + 1, vll(s + 1, -1));
	dp[0][0] = 0;
	rep(i, n) rep(j, s) {
		if(dp[i][j] == -1) continue;
		if(j + a[i] <= s) dp[i + 1][j + a[i]] += dp[i][j] + a[i];
		if(j + b[i] <= s) dp[i + 1][j + b[i]] += dp[i][j] + b[i];
	}
	if(dp.back().back() == -1) {cout << "Impossible" << endl; return 0;}
	string ans;
	ll cur = s;
	rrep(i, n) {
		if(cur - a[i] >= 0 && dp[i][cur - a[i]] != -1) ans.push_back('A'), cur -= a[i];
		else ans.push_back('B'), cur -= b[i];
	}
	reverse(all(ans));
	cout << ans << endl;
}