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
vector<string> gr;
vll delta = {0, 1, 0, -1};

ll dfs(ll y, ll x, ll y0, ll x0, ll cnt) {
	if((pll){y, x} != (pll){y0, x0}) gr[y][x] = '#';
	rep(i, 4) {
		ll dy = delta[i], dx = delta[i ^ 1];
		ll ny = y + dy, nx = x + dx;
		if(ny == y0 && nx == x0) return cnt;
		if(ny >= 0 && ny < h && nx >= 0 && nx < w && gr[ny][nx] == '.') chmax(cnt, dfs(ny, nx, y0, x0, cnt + 1));
	}
	gr[y][x] = '.';
	return cnt;
}

int main() {
	cin >> h >> w;
	gr.resize(h);
	rep(i, h) cin >> gr[i];
	vector<string> old = gr;
	ll ans = 0;
	rep(i, h) rep(j, w) {
		if(gr[i][j] == '.') chmax(ans, dfs(i, j, i, j, 1));
	}
	cout << (ans < 3 ? -1 : ans) << endl;
}