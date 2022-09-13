#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define INF (1ll << 60)
#define all(a) (a).begin(), (a).end()

template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T& a, const T& b) {if (b < a) {a = b; return 1;} return 0;}

int main() {
	map<char, pll> mp;
	mp['U'] = {-1, 0}; mp['D'] = {1, 0}; mp['L'] = {0, -1}; mp['R'] = {0, 1};
 	ll h, w; cin >> h >> w;
	vector<string> m(h); 
	ll sx, sy, gx, gy;
	rep(i, h) {
		cin >> m[i];
		rep(j, w) {
			if(m[i][j] == 'S') sy = i, sx = j;
			if(m[i][j] == 'G') gy = i, gx = j;
		}
	}
	vector<vvpll> dist(h, vvpll(w)); //好きな方向に変える操作をしているときの最短距離、していないときの最短距離
	rep(i, h) rep(j, w) dist.push_back({INF, INF});
	dist[sy][sx] = {0, 0};
	queue<pll> que; que.push({sy, sx});
	while(!que.empty()) {
		ll y = que.front().first, x = que.front().second; que.pop();
		cout << y << " " << x << "  : " << dist[y][x].first << " " << dist[y][x].second << endl;
		if(m[y][x] == '.' || m[y][x] == 'S') {
		    for(ll dy : {-1, 0, 1}) for(ll dx : {-1, 0, 1}) {
				if((dy == 0) + (dx == 0) != 1) continue;
		    	ll ny = y + dy, nx = x + dx;
		    	if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		    	if(m[ny][nx] == '#') continue;
				bool flag = false;
			    if(chmin(dist[ny][nx].first, dist[y][x].first + 1)) flag |= true;
			    if(chmin(dist[ny][nx].second, dist[y][x].second + 1)) flag |= true;

				cout << ny << " " << nx << "  " << y <<  " " << x << "  : " << flag << endl;

				if(flag) que.push({ny, nx});
		    }
		}else{
			for(ll dy : {-1, 0, 1}) for(ll dx : {-1, 0, 1}) {
				if((dy == 0) + (dx == 0) != 1) continue;
		    	ll ny = y + dy, nx = x + dx;
		    	if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		    	if(m[ny][nx] == '#') continue;
				
				if(make_pair(dy, dx) == mp[m[y][x]]) {
					bool flag = false;
			 		if(chmin(dist[ny][nx].first, dist[y][x].first + 1)) flag |= true;
			   		if(chmin(dist[ny][nx].second, dist[y][x].second + 1)) flag |= true;

					if(flag) que.push({ny, nx});
				}else{
					if(dist[y][x].first >= INF) {dist[ny][nx].first = dist[ny][nx].second = INF;} //方向変更済み

					dist[ny][nx].first = INF; //方向変更
					if(chmin(dist[ny][nx].second, dist[y][x].first + 1)) que.push({ny, nx});
				}
		    }
		}
	}
	cout << endl;
	rep(i, h) {rep(j, w) cout << dist[i][j].first << " "; cout << endl;}
	cout << endl;
	rep(i, h) {rep(j, w) cout << dist[i][j].second << " "; cout << endl;}

	rep(i, h) {rep(j, w) cout << (min(dist[i][j].first, dist[i][j].second) == INF ? -1 : min(dist[i][j].first, dist[i][j].second)) << " "; cout << endl; }
	ll ans =  min(dist[gy][gx].first, dist[gy][gx].second);
	cout << (ans != INF ? ans : -1) << endl;
}