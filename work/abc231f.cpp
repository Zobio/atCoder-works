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
#define YES printf("Yes\n"), exit(0)
#define NO printf("No\n"), exit(0)
constexpr long long MOD = 998244353LL;
constexpr long long INF = (1LL << 60);
template<class T> void setcout(T n) {cout << setprecision(n) << fixed;}
template<class T> void arrcout(T &a) { for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl; }
template<class T> void arrcout2(T &a) { for(size_t i = 0; i < a.size(); i++) { for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} }
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

template<typename V>
void shrink_coordinates(V& a) {
	/*
	座標圧縮を行う関数
	(例)
	{6, 9, 9, 2, 100} -->  {1, 2, 2, 0, 3}
	*/
	V b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	V res(a.size());
	for(long long i = 0; i < a.size(); i++) {
		res.at(i) = lower_bound(b.begin(), b.end(), a.at(i)) - b.begin();
	}
	a = res;
}


int main() {
	ll ma = 200010;
	ll n; cin >> n;
	vll a(n); rep(i, n) cin >> a[i];
	vll b(n); rep(i, n) cin >> b[i];
	vll ab; rep(i, n) ab.push_back(a[i]); rep(i, n) ab.push_back(b[i]);
	vll ol = ab;
	shrink_coordinates(ab);
	map<ll, ll> ch; rep(i, n * 2) ch[ol[i]] = ab[i];
	rep(i, n) a[i] = ch[a[i]];
	rep(i, n) b[i] = ch[b[i]];
	vll bu_a(ma + 1); rep(i, n) bu_a[a[i]]++;
	vll bu_b(ma + 1); rep(i, n) bu_b[b[i]]++;
	vll rui_a(ma + 1); rep(i, ma) rui_a[i + 1] += rui_a[i] + bu_a[i];
	vll rui_b(ma + 1); rep(i, ma) rui_b[i + 1] += rui_b[i] + bu_b[i];
	ll ans = n;
	rep(i, ma + 3) {
		cout << i << " " << rui_a[i] << " " << rui_b[i] << endl;
		cout << ans << endl;
		ans += rui_a[i] * (n - rui_b[i]);
	}
	cout << ans << endl;
}