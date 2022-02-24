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
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll h, w;
vector<string> b;
vll delta = {0, 1, 0, -1};

ll dfs(ll i, ll j, ll i0, ll j0) {
	b[i][j] = '#';
	ll res = -INF;
	rep(k, 4) {
		ll ni = i + delta[k], nj = j + delta[k ^ 1];
		if(ni == i0 && nj == j0) {
			res = 1; continue;
		}
		if(ni >= 0 && ni < h && nj >= 0 && nj < w) {
			if(b[ni][nj] == '.') chmax(res, dfs(ni, nj, i0, j0) + 1);
		}
	}
	b[i][j] = '.';
	return res;
}

int main() {
	cin >> h >> w;
	b.resize(h);
	rep(i, h) cin >> b[i];
	ll ans = 0;
	rep(i, h) rep(j, w) if(b[i][j] == '.') chmax(ans, dfs(i, j, i, j));
	cout << (ans < 3 ? -1 : ans) << endl;
}