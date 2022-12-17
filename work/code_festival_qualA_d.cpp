#include <bits/stdc++.h>
#include <atcoder/all> // AtCoder
using namespace std;
using namespace atcoder; // AtCoder
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using mint = modint998244353; // AtCoder
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vvvll = vector<vector<vector<long long>>>;
using vvvvll = vector<vector<vector<vector<long long>>>>;
using vbl = vector<bool>;
using vvbl = vector<vector<bool>>;
using vvvbl = vector<vector<vector<bool>>>;
using vvvvbl = vector<vector<vector<vector<bool>>>>;
using dll = deque<long long>;
using ddll = deque<deque<long long>>;
using dddll = deque<deque<deque<long long>>>;
using ddddll = deque<deque<deque<deque<long long>>>>;
using pll = pair<long long, long long>;
using vpll = vector<pair<long long, long long>>;
using vvpll = vector<vector<pair<long long, long long>>>;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define reep(i, a, b) for (long long i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define PI acos(-1.0)
#define YES printf("YES\n"), exit(0)
#define NO printf("NO\n"), exit(0)
#define Yes printf("Yes\n"), exit(0)
#define No printf("No\n"), exit(0)
constexpr long long MOD = 998244353LL;
constexpr long long INF = (1LL << 60);
template<class T> void setcout(T n) {cout << setprecision(n) << fixed;}
template<class T> void arrcout(T &a) { for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl; }
template<class T> void arrcout2(T &a) { for(size_t i = 0; i < a.size(); i++) { for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} }
template<class... T> constexpr auto min(T... a){return min(initializer_list<common_type_t<T...>>{a...});}
template<class... T> constexpr auto max(T... a){return max(initializer_list<common_type_t<T...>>{a...});}
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

int main() {
    string s; ll k; cin >> s >> k;
    ll d = s.size();

    vvvll dp(d + 1, vvll(2, vll(1LL << 10, 10000000000000010LL)));
    //dp[i][j][msk] : i桁目まで見て、j ? n未満 : nより大きい、使った数字の種類の集合がmskであるときの差の最小値
	dp[0][0][0] = dp[0][1][0] = 0;
	rep(i, d) rep(j, 2) rep(bits, 1LL << 10) {
        rep(p, 10) { //next number
			ll nxt = bits | (!bits && !p ? 0 : 1LL << p);
			if(__builtin_popcount(nxt) > min(i + 1, k)) continue;
			if(j | p < s[i] - '0') {
				if(dp[i][1][bits] != 10000000000000010LL && log10(dp[i][1][bits] * 10 - (p - (s[i] - '0'))) < 17 && dp[i][1][bits] * 10 - (p - (s[i] - '0')) >= 0) {
					chmin(dp[i + 1][1][nxt], dp[i][1][bits] * 10 - (p - (s[i] - '0')));
				}
			}
			if(dp[i][0][bits] != 10000000000000010LL && log10(dp[i][0][bits] * 10 + (p - (s[i] - '0'))) < 17 && dp[i][0][bits] * 10 + (p - (s[i] - '0')) >= 0) {
				chmin(dp[i + 1][0][nxt], dp[i][0][bits] * 10 + (p - (s[i] - '0')));
			}
			//cout << i + 1 << " " << j << " " << bitset<10>(bits) << "-->" << bitset<10>(nxt) << "  : " << dp[i + 1][j][nxt] << endl;
		}
    }
	ll ans = INF;
	rep(bits, 1LL << 10) if(__builtin_popcount(bits) <= k) chmin(ans, min(dp[d][0][bits], dp[d][1][bits]));
	cout << ans << endl;
}