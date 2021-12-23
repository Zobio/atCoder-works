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

vvpll g; //隣接リスト
vll dis; //距離を格納する変数 dis[goal]が答えとなる

void dijkstra(ll s) { //sからスタートして(到達可能な)全点における最短距離を求める
	dis[s] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
	//disを更新するためのqueue first:コスト second:頂点番号 (コストが低い順に処理)
	que.push({0, s});
	while(!que.empty()) {
		pair<ll, ll> p = que.top(); que.pop();
		ll v = p.second, cost = p.first;
		if(dis[v] < cost) continue;
		rep(i, g[v].size()) {
			pair<ll, ll> e = g[v][i]; //e.first:頂点番号 e.second:コスト
			if(dis[e.first] > dis[v] + e.second) {
				dis[e.first] = dis[v] + e.second;
				que.push({dis[e.first], e.first});
			}
		}
	}
}

int main() {
	ll v; cin >> v; //頂点数(vertex)
	ll e; cin >> e; //辺の数(edge)
	ll start, goal; cin >> start >> goal; start--; goal--; //出発地点、目標地点
	g.resize(v); dis.resize(v, INF);
	rep(i, e) {
		ll a, b, c; cin >> a >> b >> c; a--; b--;
		//aとbがつながっていて、そのコストはcである
		g[a].push_back({b, c});
		g[b].push_back({a, c}); //有効辺の場合は、これを消す
	}
	dijkstra(start);
	cout << dis[goal] << endl;
}