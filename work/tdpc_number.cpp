#include <bits/stdc++.h>
#include <atcoder/all> // AtCoder
using namespace std;
using namespace atcoder; // AtCoder
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using mint = modint1000000007; // AtCoder
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
	ll d; cin >> d;
	string s; cin >> s;
	ll n = s.size();
	vector<vector<vector<mint>>> dp(n + 1, vector<vector<mint>>(2, vector<mint>(d)));
	//dp[i][j][k]: i桁目までみて、未満フラグがjで、mod dがkである総数
	dp[0][0][0] = 1; //0桁目までみて、自明に未満で、mod dが0の場合の数は1
	rep(i, n) rep(j, 2) for(ll k = 0; k <= (j ? 9 : s[i] - '0'); k++) { //kは次の数
		rep(p, d) {
			dp[i + 1][j | k < s[i] - '0'][(p + k) % d] += dp[i][j][p];
		}
	}
	cout << (dp[n][0][0] + dp[n][1][0] - 1).val() << endl; //0を除外
}