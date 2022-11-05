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

vll dy = {0, 1, 0, -1};
vll dx = {1, 0, -1, 0};

ll h, w;
ll sy, sx;
vvll g;
vll done;
set<ll> around;
bool ans = false;

void dfs(ll cur) {
	done[cur] = true;
	ll y = cur / 2, x = cur % x;
	for(auto nxt : g[cur]) {
		if(!done[nxt]) {
			if(around.count(nxt)) ans |= true;
			dfs(nxt);
		}
	}
}

int main() {
	cin >> h >> w;
	vector<string> m(h); rep(i, h) cin >> m[i];
	rep(i, h) rep(j, w) if(m[i][j] == 'S') sy = i, sx = j;
	auto id = [&](ll i, ll j) {return i * w + j;}; //ラムダ式
	g.resize(h * w);
	rep(i, h) rep(j, w) {
		if(i < h - 1 && m[i][j] == '.' && m[i + 1][j] == '.') g[id(i, j)].push_back(id(i + 1, j)), g[id(i + 1, j)].push_back(id(i, j));
		if(j < w - 1 && m[i][j] == '.' && m[i][j + 1] == '.') g[id(i, j)].push_back(id(i, j + 1)), g[id(i, j + 1)].push_back(id(i, j));
	}
	rep(i, 4) {
		ll ny = sy + dy[i];
		ll nx = sx + dx[i];
		if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		around.insert(id(ny, nx));
	}
	for(auto au : around) {
		done.assign(h * w, 0);
		dfs(au);
	}
	cout << (ans ? "Yes" : "No") << endl;
}