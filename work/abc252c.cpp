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

int main() {
	ll n; cin >> n;
	vector<string> s(n); rep(i, n) cin >> s[i];
	vvll b(n, vll(10)); //b[i][j] = k ... i番目の文字列のjはk番目
	rep(i, n) rep(j, 10) b[i][s[i][j] - '0'] = j;
	vvll c(10, vll(n)); //bの転置行列
	rep(i, 10) rep(j, n) c[i][j] = b[j][i];
	rep(i, 10) sort(all(c[i]));
	vvll d(10, vll(10)); //cのバケット
	rep(i, 10) rep(j, n) d[i][c[i][j]]++;
	arrcout2(c);
	ll ans = INF;
	rep(i, 10) {
		ll cur = 0;
		rep(j, 10) {
			if(*max_element(all(d[i])) == d[i][j]) chmax(cur, 10 * (d[i][j] - 1) + j);
		}
		chmin(ans, cur);
	}
	cout << ans << endl;
}