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
#define YesNo(flag) if(flag) { cout << "Yes" << endl; } else { cout << "No" << endl; }
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

template<class T>
vector<vector<T>>mat_mul(vector<vector<T>> &a, vector<vector<T>> &b) {
	/// 行列積
	vector<vector<T>> res(a.size(), vector<T>(b[0].size()));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			  for (int k = 0; k < b.size(); k++) {
				  res[i][j] ^= a[i][k] & b[k][j];
			 }
		   }
	}
	return res;
}

template <class T>
vector<vector<T>> mat_pow(vector<vector<T>> a, long long n) {
	// 行列累乗
	vector<vector<T>> res;
	bool fir = true;
	n--;
	// 繰り返し二乗法
	while (n > 0) {
		if (n & 1) {
			if(fir) res = a;
			else res = mat_mul(a, res);
		}
		a = mat_mul(a, a);
		n >>= 1;
		cout << endl;
		arrcout2(res);
	}
	if(fir) return a;
	else return res;
}

int main() {
	ll k, m; cin >> k >> m;
	vvll a;
	rep(i, k){
		ll t; cin >> t;
		a.push_back({t});
	}
	vll c(k); rep(i, k) cin >> c[i];
	vvll mat(k, vll(k));
	rep(i, k) rep(j, k) {
		if(i == 0) mat[i][j] = c[j];
		else mat[i][j] = i == j + 1;
	}
	mat = mat_pow(mat, m - 1);
	cout << endl;
	arrcout2(mat);
	cout << endl;
	arrcout2(a);
	cout << endl;
	a = mat_mul(mat, a);
	arrcout2(a);
	cout << a.back().back() << endl;
}