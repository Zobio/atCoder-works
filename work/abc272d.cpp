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
	//移動できるのはΔX^2+ΔY^2=M^2になるときだけ　まずはそれを列挙?
	ll n, m; cin >> n >> m;
	set<pll> move;
	for(ll i = 0; i * i <= m; i++) for(ll j = 0; j * j <= m; j++) if(i * i + j * j == m) move.insert({i, j}), move.insert({i, -j}), move.insert({-i, j}), move.insert({-i, -j});
	
	vvll dist(n, vll(n, INF));
	dist[0][0] = 0;
	queue<pll> que;
	que.push({0,0});
	while(!que.empty()) {
		ll x = que.front().first, y = que.front().second; que.pop();
		for(auto au : move) {
			ll nx = x + au.first, ny = y + au.second;
			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if(chmin(dist[nx][ny], dist[x][y] + 1)) que.push({nx, ny});
		}
	}
	rep(i, n) {
		rep(j, n) {
			cout << (dist[i][j]!=INF ? dist[i][j] : -1) << " ";
		}
		cout << endl;
	}
}