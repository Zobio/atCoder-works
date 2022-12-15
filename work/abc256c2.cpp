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
	vvll a(2, vll(3));
	rep(i, 2) rep(j, 3) cin >> a[i][j];
	ll ans = 0;
	vvll b(3, vll(3, 1));

	auto check = [&]() {
		ll v1 = a[0][2] - (b[2][0] + b[2][1]);
		ll v2 = a[1][2] - (b[0][2] + b[1][2]);
		if(v1 != v2) return false;
		b[2][2] = v1;
		bool ok = true;
		rep(i, 3) rep(j, 3) ok &= b[i][j] > 0;
		return ok;
	};

	for(b[0][0] = 1; b[0][0] <= 30; b[0][0]++) for(b[0][1] = 1; b[0][1] <= 30; b[0][1]++) {
		for(b[1][0] = 1; b[1][0] <= 30; b[1][0]++) for(b[1][1] = 1; b[1][1] <= 30; b[1][1]++) {
			b[0][2] = a[0][0] - (b[0][0] + b[0][1]);
			b[1][2] = a[0][1] - (b[1][0] + b[1][1]);
			b[2][0] = a[1][0] - (b[0][0] + b[1][0]);
			b[2][1] = a[1][1] - (b[0][1] + b[1][1]);
			ans += check();
		}
	}
	cout << ans << endl;
}