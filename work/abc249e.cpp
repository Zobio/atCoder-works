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

vll ten = {1, 10, 100, 1000, 10000, 100000};

int main() {
	ll n, p; cin >> n >> p;
	modint::set_mod(p);
	vector<vector<modint>> dp(n + 1, vector<modint>(n + 1)); //dp[i][j] : 圧縮後(T)の長さがiで、圧縮前(S)の長さがjの個数
	dp[0][0] = 1;
	vector<vector<modint>> rui(n + 1, vector<modint>(n + 2)); //累積和
	fill(all(rui[0]), 1); rui[0][0] = 0;
	//今ある文字列に新たな文字列Xを追加するとする。ここでXは全て同じ文字で構成されてて、個数をxとする。
	//すると、Sはx文字、Tは1 + log10(x)文字だけ増える。
	//従って、dp[i + 1 + log10(x)][j + x] = c * dp[i][j](cはi=0のとき26, それ以外のとき25)
	reps(i, n) reps(j, n) {
		// iがT, jがSに対応
		reps(k, 4) {
			if(i - k - 1 < 0) continue; //文字列Tの増分は、"k + 1" (1の意味は接頭辞のアルファベット)
			ll c = i - k - 1 == 0 ? 26 : 25; //遷移前の文字列が空文字列なら26通り、それ以外なら25通り(同じ文字は使えないので)
			ll x = max(j - ten[k - 1] + 1, 0ll), y = max(j - ten[k] + 1, 0ll); //Sがj文字になる範囲は、[j - 10^k, j - 10^(k-1)](Tではk桁になるなので)
			dp[i][j] += (rui[i - k - 1][x] - rui[i - k - 1][y]) * c;
		}
		rui[i][j + 1] = rui[i][j] + dp[i][j];
	}
	modint ans = 0;
	reps(i, n - 1) ans += dp[i][n];
	cout << ans.val() << endl;
}