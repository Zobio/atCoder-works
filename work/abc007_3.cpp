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
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << (a.at(i).at(j) == INF ? -1 : a.at(i).at(j)); cout << endl;}
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

vll dx = {0, 1, 0, -1};
vll dy = {1, 0, -1, 0};


int main() {
	ll h, w; cin >> h >> w;
	ll sy, sx, ey, ex; cin >> sy >> sx >> ey >> ex; sy--; sx--; ey--; ex--;
	vector<string> s(h); rep(i, h) cin >> s[i];
	queue<pll> que;
	que.push({sy, sx});
	vvll dis(h, vll(w, INF));
	dis[sy][sx] = 0;
	while(!que.empty()) {
		ll cy = que.front().first, cx = que.front().second; que.pop();
		rep(i, 4) {
			ll ny = cy+ dy[i], nx = cx + dx[i];
			if(nx >= 0 && nx < w && ny >= 0 && ny < h) if(s[ny][nx] == '.') if(chmin(dis[ny][nx], dis[cy][cx] + 1)) {
				que.push({ny, nx});
			}
		}
	}
	cout << dis[ey][ex] << endl;
}