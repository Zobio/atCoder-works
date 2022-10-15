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
#define reep(i, a, b) for(long long i = a; i < b; i++)
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
#define YESS {printf("Yes\n"); return 0;}
#define NOO {printf("No\n"); return 0;}
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll h, w; cin >> h >> w;
	ll sy, sx, gy, gx; cin >> sy >> sx >> gy >> gx; sy--; sx--; gy--; gx--;
	vector<string> m(h);
	rep(i, h) cin >> m[i];
	vvll d = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; //上左下右
	vector<vector<vector<bool>>> done(h, vector<vector<bool>>(w, vector<bool>(4))); //done[i][j][k] : マス(i, j)で方向kの行動をしたことがあるか
	ll y = sy, x = sx, state = 0, ans = 0;
	vll perm = {1, 0, 3, 2}; //方向転換の順番(左、直進、右、後ろ)
	while(1) {
		if(y == gy && x == gx) {cout << ans << endl; return 0;}

		bool flag = false;
		for(auto p : perm) {
			ll dy = d[(state + p) % 4][0], dx = d[(state + p) % 4][1];
			ll ny = y + dy, nx = x + dx;
			if(ny < 0 || ny >= h || nx < 0 || nx >= w || m[ny][nx] == '#') continue;
			if(done[ny][nx][(state + p) % 4]) {cout << -1 << endl; return 0;}
			state = (state + p) % 4;
			done[ny][nx][state] = true;
			flag = true;
			y = ny; x = nx;
			break;
		}

		if(!flag) {cout << -1 << endl; return 0;}
		ans++;
	}
}