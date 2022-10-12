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
#define reep(i, a, b) for(long long i = a; i < b; i++)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
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
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

struct edge{
	ll to;
	ll cost;
	ll busy;
};


int main() {
	ll n, m, t, k; cin >> n >> m >> t >> k; //混雑度 D-|T-t| <= Kとなるようにする
	vector<vector<edge>> g(n);
	rep(i, m) {
		ll a, b, c, d; cin >> a >> b >> c >> d; a--; b--;
		g[a].push_back({b, c, d});
		g[b].push_back({a, c, d});
	}
	vll dist(n, INF);
	dist[0] = 0;
	priority_queue<pll, vpll, greater<pll>> que;
	que.push({0, 0});
	while(que.size()) {
		pll cur = que.top(); que.pop();
		ll v = cur.second;
		if(dist[v] < cur.first) continue;
		rep(i, g[v].size()) {
			auto nxt = g[v][i];
			ll e = nxt.to;
			ll time = dist[v] + nxt.cost;
			ll wait = INF;
			ll A = -nxt.busy + k + t, B = nxt.busy - k + t;
			if(A > B) A = INF, B = -INF; //例外処理 対象区間が存在しない
			if(B <= dist[v]) wait = 0;
			else if(time <= A) wait = 0;
			else wait = B - dist[v];
			if(chmin(dist[e], time + wait)) que.push({dist[e], e});
		}
	}
	cout << (dist.back() != INF ? dist.back() : -1) << endl;
}