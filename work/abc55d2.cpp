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

int main() {
	//1番目と2番目の動物を確定させれば、他の動物を連鎖的にすべて確定させることができる
	ll n; cin >> n;
	string s; cin >> s;
	rep(state, 1LL << 2) {
		vll a(n);
		a[0] = state & 1;
		a[1] = state >> 1 & 1;
		rep(i, n - 2) {
			ll nxt = (s[i + 1] == 'x') ^ (a[i] == 0) ^ (a[i + 1] == 0); //2個隣がSで、1個隣がSで、1個隣の状態がxならW
			a[i + 2] = nxt;
		}
		bool flag = true;
		rep(i, 4) { //矛盾がないかチェック
			ll l = (n - 2 + i) % n;
			ll mid = (n - 1 + i) % n;
			ll r = (n + i) % n;
			flag &= (a[mid] == 1) ^ (s[mid] == 'o') ^ (a[l] == 0) ^ (a[r] == 0); //真ん中がSで、両隣がSで、真ん中がoならOK
		}
		if(flag) {
			rep(i, n) cout << (a[i] ? 'W' : 'S');
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}