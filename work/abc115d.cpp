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

vll sum, patty;

ll f(ll level, ll x) {
	if(level == 0) return 1;

	if(x < 1) return 0;
	x--;
	if (x < sum[level - 1]) return f(level - 1, x);
	x -= sum[level - 1];

	if(x < 1) return patty[level - 1] + 1; //ここはパティ
	x--;
	if(x < sum[level - 1]) return patty[level - 1] + 1 + f(level - 1, x);
	x -= sum[level - 1];

	return patty[level - 1] * 2 + 1;

}

int main() {
	ll n, x; cin >> n >> x; x--; //0-indexed
	sum.resize(n + 1), patty.resize(n + 1);
	sum.front() = patty.front() = 1;
	rep(i, n) sum[i + 1] = sum[i] * 2 + 3;
	rep(i, n) patty[i + 1] = patty[i] * 2 + 1;
	cout << f(n, x) << endl;
}