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

int main() { //01BFS
	ll h, w; cin >> h >> w;
	pll st, en; cin >> st.first >> st.second >> en.first >> en.second; st.first--; st.second--; en.first--; en.second--;
	vector<string> gr(h); rep(i, h) cin >> gr[i];
	vvpll dis(h, vpll(w, make_pair(INF, 0))); dis[st.first][st.second].first = 0; //stから"方向が変わる回数"の最小値とそこについたときの方向
	deque<pll> que; que.push_back(st);
	while(!que.empty()) {
		ll y = que.front().first, x = que.front().second; que.pop_front();
		rep(i, 4) {
			ll nx = x + dx[i], ny = y + dy[i];
			if (ny >= 0 && ny < h && nx >= 0 && nx < w && gr[ny][nx] == '.' && dis[ny][nx].first >= dis[y][x].first + !((1 << i) & (dis[y][x].second))) {
				if(dis[ny][nx].first == dis[y][x].first + 1 && !((1 << i) & (dis[ny][nx].second))) {
					dis[ny][nx] = {dis[y][x].first, dis[ny][nx].second | (1 << i)};
					que.push_front({ny, nx});
				}
				else if((1 << i) & (dis[y][x].second)) {
					dis[ny][nx] = {dis[y][x].first, (1 << i)};
					que.push_front({ny, nx});
				}else{
					dis[ny][nx] = {dis[y][x].first + 1, (1 << i)};
					que.push_back({ny, nx});
				}
			}
		}
	}
	rep(i, h) {rep(j, w) cout << dis[i][j].first << " " << bitset<4>(dis[i][j].second) << " "; cout << endl;}
	cout << dis[en.first][en.second].first - 1 << endl;
}