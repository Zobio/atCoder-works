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
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

vll dx = {0, 1, 0, -1};
vll dy = {1, 0, -1, 0}; //4方向ベクトル

int main() {
	ll h, w; cin >> h >> w;
	pll st, en; cin >> st.first >> st.second >> en.first >> en.second; st.first--; st.second--; en.first--; en.second--;
	vector<string> gr(h); rep(i, h) cin >> gr[i];
	vvvll dist(h, vvll(w, vll(4, INF))); //dist[i][j][k] ... マス(i, j)でdx[k]+dy[k]の方向を向いているときのコストの最小値
	deque<ll> que;
	rep(i, 4) {
		dist[st.first][st.second][i] = 0;
		que.push_back({st.first * 10000 + st.second * 10 + i}); //ハッシュ化
	}
	while(!que.empty()) {
		ll cy = que.front() / 10000, cx = que.front() % 10000 / 10, d = que.front() % 10; que.pop_front();
		rep(i, 4) { //方向転換
			if(dist[cy][cx][i] > dist[cy][cx][d] + 1) {
				dist[cy][cx][i] = dist[cy][cx][d] + 1;
				que.push_back(cy * 10000 + cx * 10 + i);
			}
		}
		ll ty = cy + dy[d], tx = cx + dx[d];
		if(ty >= 0 && ty < h && tx >= 0 && tx < w && gr[ty][tx] == '.' && dist[ty][tx][d] > dist[cy][cx][d]) { //進む
			dist[ty][tx][d] = dist[cy][cx][d];
			que.push_front(ty * 10000 + tx * 10 + d);
		}
	}
	ll ans = INF; rep(i, 4) chmin(ans, dist[en.first][en.second][i]);
	cout << ans << endl;
}