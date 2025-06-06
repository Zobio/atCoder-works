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

int main() {
	ll h, w; cin >> h >> w;
	vector<string> g(h); rep(i, h) cin >> g[i];
	vvpll m(h, vpll(w));
	rep(i, h) rep(j, w) {
		if(g[i][j] == 'U') m[i][j] = {-1, 0};
		if(g[i][j] == 'D') m[i][j] = {1, 0};
		if(g[i][j] == 'L') m[i][j] = {0, -1};
		if(g[i][j] == 'R') m[i][j] = {0, 1};
	}
	vvll used(h, vll(w)); used[0][0] = true;
	ll y = 0, x = 0;
	while(1) {
		ll ny = y + m[y][x].first, nx = x + m[y][x].second;
		if(ny < 0 || ny >= h || nx < 0 || nx >= w) {cout << y + 1 << " " << x + 1 << endl; return 0;}
		if(used[ny][nx]) {cout << -1 << endl; return 0;}
		used[ny][nx] = true;
		y = ny; x = nx;
	}
}