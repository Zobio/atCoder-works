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

struct UnionFind {
	long long groups;
	vector<long long> parents;

	UnionFind(long long n) {
		groups = n;
		parents = vector<long long>(n, -1);
	}

	long long find(long long x) {
		if (parents.at(x) < 0) {
			return x;
		}else{
			parents[x] = find(parents[x]);
			return parents[x];
		}
	}

	void unite(long long x, long long y) {
		x = find(x);
		y = find(y);

		// already united
		if (x == y)
			return;

		groups--;

		if (parents[x] > parents[y])
			swap(x, y);

		parents[x] += parents[y];
		parents[y] = x;
	}

	long long size(long long x) {
		return -parents[find(x)];
	}

	bool issame(long long x, long long y) {
		return find(x) == find(y);
	}

	vector<long long> roots() {
		vector<long long> ret;
		for (long long i = 0; i < parents.size(); i++)
			if (parents[i] < 0)
				ret.push_back(i);
		return ret;
	}

	long long group_count() {
		return groups;
	}
};

ll h, w;
vector<string> m;
ll sy, sx;
vvll g;
vvll done;
bool ans = false;

int main() { 
	cin >> h >> w;
	m.resize(h); rep(i, h) cin >> m[i];
	rep(i, h) rep(j, w) if(m[i][j] == 'S') sy = i, sx = j;
	g.resize(h * w);
	rep(i, h) rep(j, w) {
		if(m[i][j] == '#') continue;
		for(ll dy : {-1, 0, 1}) for(ll dx : {-1, 0, 1}) {
			if((dy == 0) + (dx == 0) != 1) continue;
			ll ny = i + dy, nx = j + dx;
			if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if(m[ny][nx] == '#') continue;
			g[i * w + j].push_back(ny * w + nx);
		}
	}
	UnionFind uf(h * w);
	vvll dist(h, vll(w, INF));
	dist[sy][sx] = 0;
	queue<pll> que;
	que.push({sy, sx});
	while(que.size()) {
		ll y = que.front().first, x = que.front().second; que.pop();
		for(auto nxt : g[y * w + x]) {
			ll ny = nxt / w, nx = nxt % w;
			if(uf.issame(y * w + x, ny * w + nx)) ans |= true;
			if(chmin(dist[ny][nx], dist[y][x] + 1)) uf.unite(y * w + x, ny * w + nx), que.push({ny, nx});
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
}