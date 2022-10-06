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
	setcout(15);
	ll n; cin >> n;
	vll cnt(110);
	ld sum = 0;
	vll l(n), r(n); rep(i, n) {
		cin >> l[i] >> r[i], l[i]--, r[i]--;
		reep(j, l[i], r[i] + 1) cnt[j]++, sum++;
	}
	vector<vector<ld>> dp(n + 1, vector<ld>(110)); // dp[i][j] : 要素数iで、先頭の値がjであるときの転倒数の期待値
	rrep(i, n - 1) rep(j, 100) rep(k, 100) {
		if(!(l[i] <= j && j <= r[i])) continue;
		if(!(l[i + 1] <= k && k <= r[i + 1])) continue;
		dp[i][j] += (1 + (j > k)) * 1 / (r[i + 1] - l[i + 1] + 1) * dp[i + 1][k];
		if(dp[i][j]) cout << i << " " << j << "  " << dp[i][j] << endl;
	}
	arrcout2(dp);
}