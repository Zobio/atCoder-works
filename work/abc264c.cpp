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
#define mint modint998244353
#define INF (1LL << 60)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll popcount(ll num) {
	ll ret = 0;
	while(num) ret += num & 1, num >>= 1;
	return ret;
}

int main() {
	ll h1, w1; cin >> h1 >> w1;
	vvll a(h1, vll(w1)); rep(i, h1) rep(j, w1) cin >> a[i][j];
	ll h2, w2; cin >> h2 >> w2;
	vvll b(h2, vll(w2)); rep(i, h2) rep(j, w2) cin >> b[i][j];
	rep(bits1, 1ll << h1) rep(bits2, 1ll << w1) {
		if(popcount(bits1) != h2 || popcount(bits2) != w2) continue;
		vll m1(h1, -1), m2(w1, -1);
		ll cnt = 0;
		rep(i, h1) if(bits1 >> i & 1) m1[i] = cnt, cnt++;
		cnt = 0;
		rep(i, w1) if(bits2 >> i & 1) m2[i] = cnt, cnt++;
		bool flag = true;
		rep(i, h1) rep(j, w1) {
			if(m1[i] == -1 || m2[j] == -1) continue;
			flag &= a[i][j] == b[m1[i]][m2[j]];
		}
		if(flag) {cout << "Yes" << endl; return 0;}
	}
	cout << "No" << endl; return 0;
}