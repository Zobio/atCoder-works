#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 1000000007LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll n, m, t;
vector<vector<pair<ll, ll>>> g;
vll dist;
vll a;

void dijkstra(ll goal) {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	dist[goal] = 0;
	pq.push(make_pair(dist[goal], goal));
	while(!pq.empty()) {
		pair<ll, ll> p = pq.top(); pq.pop();
		ll v = p.second;
		if(dist[v] < p.first) continue;
		rep(i, g[v].size()) {
			pair<ll, ll> e = g[v][i];
			chmin(dist[e.first], dist[v] + e.second);
			pq.push(make_pair(dist[e.first], e.first));
		}
	}
}

int main() {
	cin >> n >> m >> t;
	g.resize(n);
	a.resize(n);
	dist.assign(n, INF);
	rep(i, n) cin >> a.at(i);
	rep(i, m) {
		ll aa, bb, cc;
		cin >> aa >> bb >> cc;
		aa--; bb--;
		g[aa].push_back(make_pair(bb, cc));
	}
	ll ans = 0;
	rep(i, n) chmax(ans, (t - dist[i] * 2) + a[i]);
	cout << ans << endl;
}