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
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;}
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() { //O(N)のDP?
	ll n; cin >> n;
	vll a(n); rep(i, n) cin >> a[i];
	vvll dp(n, vll(2));
	ll ans = INF;
	rep(i, 2) {
		dp[0][i] = a[0] * i, dp[0][1 - i] = INF; //iが0の時はdp[0][0] = 0, dp[0][1] = INF, iが1の時はdp[0][1] = a[0], dp[0][0] = INF
		for(ll j = 0; j < n - 1; j++) {
			dp[j + 1][0] = dp[j][1];
			dp[j + 1][1] = min(dp[j][0], dp[j][1]) + a[j + 1];
		}
		if(i == 0) chmin(ans, dp[n - 1][1]); //n番目で餌を与えないといけない
		else chmin(ans, min(dp[n - 1][0], dp[n - 1][1])); //0番目で餌を与えているので、n番目では餌を与えても与えなくても良い
	}
	cout << ans << endl;
}