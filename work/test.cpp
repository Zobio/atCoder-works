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

vvll g1;
vector<vector<pair<ll, ll>>> g2;
queue<ll> que;
vll d1, d2;
ll n, m, k, s;
ll p, q;

void dijkstra(ll s) {
	d2[s] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
	//disを更新するためのqueue first:コスト second:頂点番号 コストが低い順に処理
	que.push({0, s});
	while(!que.empty()) {
		pair<ll, ll> pa = que.top(); que.pop();
		ll v = pa.second;
		if(d2[v] < pa.first) continue;
		rep(i, g2[v].size()) {
			pair<ll, ll> e = g2[v][i];
			//cout << e.first << " " << e.second << endl; //目標地点、コスト
			if(d2[e.first] > d2[v] + e.second) {
				d2[e.first] = d2[v] + e.second;
				//cout << e.first + 1 << " " << d2[e.first] << endl;
				que.push({d2[e.first], e.first});
			}
		}
	}
}

int main() {
	cin >> n >> m >> k >> s >> p >> q;
	d1.resize(n, INF); d2.resize(n, INF); g1.resize(n); g2.resize(n);
	//d1, g1は危険な街を探索するのに行うBFS用、d2, g2はBFSをもとに最短経路を探索するダイクストラ法用
	rep(i, k) {ll tmp; cin >> tmp; tmp--; que.push(tmp), d1[tmp] = 0;}
	rep(i, m) {ll a, b; cin >> a >> b; a--; b--;g1[a].push_back(b); g1[b].push_back(a);}
	while(!que.empty()) { //BFS
		int v = que.front(); que.pop();
		for (auto nv : g1[v]) {
            if (d1[nv] == INF) {
                d1[nv] = d1[v] + 1;
                que.push(nv);
            }
        }
	}
	rep(i, n) rep(j, g1[i].size()) {
		if(d1[g1[i][j]] == 0) continue;
		else if(d1[g1[i][j]] > s) g2[i].push_back({g1[i][j], p});
		else g2[i].push_back({g1[i][j], q});
		//cout << i + 1 << " " << g2[i].back().first + 1 << " " << g2[i].back().second << endl;
	}
	dijkstra(0);
	cout << d2[n - 1] - (d1[n - 1] > s ? p : q) << endl;
	//危険な街をダイクストラ(orBFS)で列挙→コストをつけてもう一回ダイクストラ
}