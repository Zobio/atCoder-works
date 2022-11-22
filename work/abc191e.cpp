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
#define reep(i, a, b) for(long long i = a; i < b; i++)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define dll deque<long long>
#define ddll deque<dque<long long>>
#define dddll deque<deque<deque<long long>>>
#define ddddll deque<deque<deque<deque<long long>>>>
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
#define MOD 998244353LL
#define mint modint998244353
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

vector<long long> dijkstra(ll s, vvpll g) { 
	/*
	sからスタートして(到達可能な)全点における最短距離を求める
	グラフg firstに頂点番号 secondにコスト
	*/
	vector<ll> dis(g.size(), INF);
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
	return dis;
}

int main() {
	ll n, m; cin >> n >> m;
	vvpll g(n), h(n);
	rep(i, m) {
		ll a, b, c; cin >> a >> b >> c; a--; b--;
		g[a].push_back({b, c});
		h[b].push_back({a, c});
	}
	rep(i, n) {
		vll dist1 = dijkstra(i, g);
		vll dist2 = dijkstra(i, h);
		ll ans = INF;
		rep(j, n) if(j != i) chmin(ans, dist1[j] + dist2[j]);
		for(auto au : g[i]) if(au.first == i) chmin(ans, au.second);
		cout << (ans >= INF / 4 ? -1 : ans) << endl;
	}
}