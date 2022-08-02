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
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? "" : "") << a.at(i).at(j); cout << endl;}
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

ll h, w, a, b;
vvll m;

ll sumW(ll k, ll num) {
	ll ret = 0;
	rep(i, h) ret += m[i][k] == num;
	return ret;
}

int main() {
	cin >> h >> w >> a >> b;
	m.resize(h, vll(w));
	rep(i, h) rep(j, w) {
		bool flag1 = false, flag2 = false; //
		if(w - accumulate(all(m[i]), 0ll) > a) m[i][j] = 1; //0が横方向で多い
		else if(accumulate(all(m[i]), 0ll) == w - a) m[i][j] = 0; //0が横方向に必要最低限ある
		else if(h - sumW(j, 1) > b) m[i][j] = 1; //0が縦方向で多い
		else if(sumW(j , 0))
	}
	arrcout2(m);
}