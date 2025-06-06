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
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i).val(); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j).val(); cout << endl;}
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

template<typename T>
T mpow(T a, T n, T m) {
	/*a^n % mを返す
	(例)
	pow(2, 10, 1000) --> 24
	計算量はlog(n)
	*/
	T ret = 1;
	while(n > 0) {
		if (n & 1) ret = ret * a % m;
		a = a % m * a % m;
		n >>= 1;
	}
	return ret;
}

int main() {
	ll n, m, k; cin >> n >> m >> k;
	if(k == 0) {cout << mpow(m, n, MOD) << endl; return 0;}
	vector<vector<modint998244353>> dp(n, vector<modint998244353>(m)); //dp[i][j] ... i番目まで見て、最後の数がjである通り数(∴答えはaccumulate(dp(n)))
	fill(dp.front().begin(), dp.front().end(), 1); //最初は1通り
	rep(i, n - 1) {
		vector<modint998244353> rui(m + 1);
		rep(j, m) rui[j + 1] = rui[j] + dp[i][j];
		rep(j, m) {
			if(j - k >= 0) dp[i + 1][j] += rui[j - k + 1]; //+1は累積和の添え字とdpの添え字の差
			if(j + k <= m - 1) dp[i + 1][j] += rui.back() - rui[j + k - 1 + 1]; ////+1は累積和の添え字とdpの添え字の差
		}
	}
	modint998244353 ans = 0; rep(i, dp.back().size()) ans += dp.back().at(i).val();
	cout << ans.val() << endl;
}