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

vll dx = {-2, -1, 0, 1, 2};
vll dy = {-2, -1, 0, 1, 2};

int main() {
	ll h, w; cin >> h >> w;
	pair<ll, ll> st, en;
	cin >> st.second >> st.first; st.first--; st.second--;
	cin >> en.second >> en.first; en.first--; en.second--;
	vector<string> s(h); rep(i, h) cin >> s[i];
	deque<pair<ll, ll>> que; //キュー{x, y}
	vvll dis(h, vll(w, INF)); //距離を格納する変数 dis[en.second][en.first]が答えとなる
	dis[st.second][st.first] = 0;
	que.push_back({st.first, st.second});
	while(!que.empty()) {
		pair<ll, ll> p = que.front(); que.pop_front();
		ll cx = p.first, cy = p.second;
		if(cx == en.first && cy == en.second) {cout << dis[cy][cx] << endl; return 0;}
		rep(i, 4) {//歩き
			vll dd = {1, 0, -1, 0};
			ll tx = cx + dd[i], ty = cy + dd[i^1];
			if(ty < 0 || ty >= h || tx < 0 || tx >= w) continue;
			else if(s[ty][tx] == '#') continue;
			if(dis[ty][tx] > dis[cy][cx]) {
				dis[ty][tx] = dis[cy][cx];
				que.push_front({tx, ty});
			}
		}
		for(auto i : dx) for (auto j : dy) {//ワープ
			ll tx = cx + i, ty = cy + j;
			if(ty < 0 || ty >= h || tx < 0 || tx >= w) continue;
			else if(s[ty][tx] == '#') continue;
			if(dis[ty][tx] > dis[cy][cx] + 1) {
				dis[ty][tx] =  dis[cy][cx] + 1;
				que.push_back({tx, ty});
			}
		}
	}
	cout << -1 << endl;
}