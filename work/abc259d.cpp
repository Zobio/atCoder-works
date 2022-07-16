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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll n, sx, sy, tx, ty;
vll x, y, r;
vvll g;

int main() {
	cin >> n;
	cin >> sx >> sy >> tx >> ty;
	x.resize(n); y.resize(n); r.resize(n);
	rep(i, n) cin >> x[i] >> y[i] >> r[i];
	g.resize(n);
	rep(i, n) for(ll j = i + 1; j < n; j++) {
		ll d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
		if(r[i] * r[i] + 2 * r[i] * r[j] + r[j] * r[j] < d) continue;
		if(r[i] * r[i] - 2 * r[i] * r[j] + r[j] * r[j] > d) continue;
		g[i].push_back(j), g[j].push_back(i);
	}
	vvll dist(n, vll(n, INF));
	rep(i, n) {
		queue<ll> que; que.push(i);
		dist[i][i] = 0;
		while(!que.empty()) {
			ll cur = que.front(); que.pop();
			for(auto au : g[cur]) {
				if(dist[i][au] != INF) continue;
				dist[i][au] = dist[i][cur] + 1;
				que.push(au);
			}
		}
	}
	rep(i, n) rep(j, n){
		if(dist[i][j] == INF) continue;
		ll dx1 = abs(sx - x[i]), dy1 = abs(sy - y[i]);
		ll dx2 = abs(tx - x[j]), dy2 = abs(ty - y[j]);
		if(dx1 * dx1 + 2 * dx1 * dy1 + dy1 * dy1 != r[i] * r[i]) continue;
		if(dx2 * dx2 + 2 * dx2 * dy2 + dy2 * dy2 != r[j] * r[j]) continue;
		cout << "Yes" << endl; return 0;
	}
	cout << "No" << endl;
}