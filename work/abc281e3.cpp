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
	ll n, m, k; cin >> n >> m >> k;
	vll a(n); rep(i, n) cin >> a[i];
	multiset<ll> small, big; //K個、M-K個
	rep(i, m) {
		if(small.size() < k) small.insert(a[i]);
		else if(*small.rbegin() < a[i]) big.insert(a[i]);
		else {
			big.insert(*small.rbegin());
			small.erase(small.find(*small.rbegin()));
			small.insert(a[i]);
		}
	}
	ll sum = 0;
	for(auto au : small) sum += au;
	cout << sum << endl;
	reep(i, m, n) {
		//挿入
		if(*small.rbegin() < a[i]) big.insert(a[i]);
		else small.insert(a[i]), sum += a[i];
		//削除
		if(small.count(a[i - m])) sum -= a[i - m], small.erase(small.find(a[i - m]));
		else big.erase(big.find(a[i - m]));
		if(small.size() > k) {
			sum -= *small.rbegin();
			big.insert(*small.rbegin());
			small.erase(small.find(*small.rbegin()));
		}
		else if(small.size() < k) {
			sum += *big.begin();
			small.insert(*big.begin());
			big.erase(big.find(*big.begin()));
		}
		cout << sum << endl;
	}
}