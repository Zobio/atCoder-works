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
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }


ll n;//頂点数
struct edge{ll to, cost;};
vector<vector<edge>> g;
//g[i][j].first : 地点iの目標地点 g[i][j].second : 地点iのコスト (j番目というのはあまり関係ない)
vll dis;
//dis[i] ... 初期地点から地点iまでの最短距離(INFで要初期化)

void dijkstra(ll s) {
	/*diskstra法
	初期地点sが与えられたら、全点における最短距離を探索する
	*/
	dis[s] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
	//disを更新するためのqueue first:コスト second:頂点番号 コストが低い順に処理
	que.push({0, s});
	while(!que.empty()) {
		pair<ll, ll> p = que.top(); que.pop();
		ll v = p.second;
		if(dis[v] < p.first) continue;
		rep(i, g[v].size()) {
			edge e = g[v][i];
			if(dis[e.to] > dis[v] + e.cost) {
				dis[e.to] = dis[v] + e.cost;
				que.push({dis[e.to], e.to});
			}
		}
	}
}

int main() {
	cin >> n;
	g.resize(n + 1);
	dis.resize(n + 1, INF);
	reps(i, n) {
		ll a; cin >> a;
		edge tmp; tmp.cost = a;
		if(i != n) tmp.to = i + 1;
		else tmp.to = 1;
		g[i].push_back(tmp);
	}
	reps(i, n) {
		ll a; cin >> a;
		edge tmp; tmp.to = i; tmp.cost = a;
		g[0].push_back(tmp);
	}
	dijkstra(0);
	reps(i, n) cout << dis[i] << endl;
}