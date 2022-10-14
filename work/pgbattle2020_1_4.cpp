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

int main() {
	ll n, m; cin >> n >> m;
	vvll g(n);
	rep(i, m) {
		ll a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
	}
	vll dist(n, INF); dist[0] = 0;
	vector<string> path(n); path[0] = "1";
	queue<ll> que; que.push(0);
	while(que.size()) {
		ll cur = que.front(); que.pop();
		for(auto nxt : g[cur]) {
			if(chmin(dist[nxt], dist[cur] + 1)) path[nxt] = path[cur] + " " + to_string(nxt + 1), que.push(nxt);
			else if(dist[nxt] == dist[cur] + 1 && path[nxt] > path[cur] + to_string(nxt + 1)) path[nxt] = path[cur] + " " + to_string(nxt + 1), que.push(nxt);
		}
	}
	if(path.back().empty()) cout << -1 << endl;
	else {
		ll sz = path.back().size();
		rep(i, sz) {
			if(path.back().at(i) == ' ') {while(i < sz && path.back().at(i) == ' ') i++; cout << " ";}
			cout << path.back().at(i);
		}
		cout << endl;
	}
}