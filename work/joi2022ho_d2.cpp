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
vll dis;

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
				cout << v << " " << e.first << " " << dis[e.first] << endl;
				arrcout(dis);
			}
		}
	}
}

int main() {
	ll n, k, m; cin >> n >> k >> m; //n:駅 k:許容される駅数 m:列車の数
	vpll tr(m); rep(i, m) cin >> tr[i].first >> tr[i].second, tr[i].first--, tr[i].second--;
	ll q; cin >> q; //計画数
	vpll p(q); rep(i, q) cin >> p[i].first >> p[i].second, p[i].first--, p[i].second--;
	g.resize(n); dis.resize(n, INF);
	rep(i, m) {
		ll from = tr[i].first, to = tr[i].second;
		if(from < to) for(ll j = from; j <= min(from + k - 1, to - 1); j++) { //始点
			for(ll k = j + 1; k <= to; k++) g[j].push_back({k, 1});
		}
		else for(ll j = from; j >= max(from - k + 1, to + 1); j--) { //始点
			for(ll k = j - 1; k >= to; k--) g[j].push_back({k, 1});
		}
	}
	rep(i, q) {
		dis.resize(n, INF);
		ll st = p[i].first, en = p[i].second;
		dijkstra(st);
		cout << st << " " << en << " : "; arrcout(dis);
		cout << dis[en] << endl;
	}
}