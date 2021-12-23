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

int main() {//BFSによる解答
	ll h, w; cin >> h >> w;
	vector<string> c(h);
	rep(i, h) cin >> c[i];
	vll fx = {-1, 0, 1, 0}, fy = {0, 1, 0, -1}; //方向ベクトル(4方向)
	ll ans = 0;
	rep(a, h) rep(b, w) {
		queue<pair<ll, ll>> q;		 //キュー
		vvll d(1010, vll(1010, -1)); //距離を保存しておく配列
		q.push({a, b}); if(c[a][b] == '.') d[a][b] = 1;
		while(!q.empty()) {
			ll x = q.front().first, y = q.front().second; q.pop();
			rep(i, 4) {
				ll tx = x + fx[i], ty = y + fy[i];
				if(tx >= 0 && tx < h && ty >= 0 && ty < w) {
					if(c[tx][ty] == '.' && c[x][y] == '.' && d[tx][ty] == -1) {
						chmax(d[tx][ty], d[x][y] + 1);
						q.push({tx, ty});
					}
				}
			}
		}
		rep(i, h) rep(j, w) chmax(ans, d[i][j]);
	}
	cout << ans << endl;
}
