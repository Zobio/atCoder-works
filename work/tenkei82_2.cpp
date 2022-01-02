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
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

vector<ull> pow10(20);

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
		a = a * a % m;
		n >>= 1;
	}
	return ret;
}

void init() {
	pow10[0] = 1;
	rep(i, 19) pow10[i + 1] = pow10[i] * 10ull;
}

int main() {
	init();
	ull l, r; cin >> l >> r;
	ull ans = 0;
	reps(i, 19) {
		unsigned long long vl = max(l, pow10[i - 1]);
		unsigned long long vr = min(r, pow10[i] - 1ull);
		if (vl > vr) continue;
	}
}