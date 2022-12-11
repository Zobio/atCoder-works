#include <bits/stdc++.h>
#include <atcoder/all> // AtCoder
using namespace std;
using namespace atcoder; // AtCoder
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using mint = modint998244353; // AtCoder
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vvvll = vector<vector<vector<long long>>>;
using vvvvll = vector<vector<vector<vector<long long>>>>;
using vbl = vector<bool>;
using vvbl = vector<vector<bool>>;
using vvvbl = vector<vector<vector<bool>>>;
using vvvvbl = vector<vector<vector<vector<bool>>>>;
using dll = deque<long long>;
using ddll = deque<deque<long long>>;
using dddll = deque<deque<deque<long long>>>;
using ddddll = deque<deque<deque<deque<long long>>>>;
using pll = pair<long long, long long>;
using vpll = vector<pair<long long, long long>>;
using vvpll = vector<vector<pair<long long, long long>>>;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define reep(i, a, b) for (long long i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define PI acos(-1.0)
#define YES printf("YES\n"), exit(0)
#define NO printf("NO\n"), exit(0)
#define Yes printf("Yes\n"), exit(0)
#define No printf("No\n"), exit(0)
constexpr long long MOD = 998244353LL;
constexpr long long INF = (1LL << 60);
template<class T> void setcout(T n) {cout << setprecision(n) << fixed;}
template<class T> void arrcout(T &a) { for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl; }
template<class T> void arrcout2(T &a) { for(size_t i = 0; i < a.size(); i++) { for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} }
template<class... T> constexpr auto min(T... a){return min(initializer_list<common_type_t<T...>>{a...});}
template<class... T> constexpr auto max(T... a){return max(initializer_list<common_type_t<T...>>{a...});}
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

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

vll dy = {0, 1, 0, -1};
vll dx = {1, 0, -1, 0};

int main() {
	ll h, w; cin >> h >> w;
	ll n = h * w;
	vvll a(h, vll(w)); rep(i, h) rep(j, w) cin >> a[i][j];
	auto id = [&](ll p, ll q) {
		return p * w + q;
	};
	UnionFind uf(n);
	rep(y, h) rep(x, w) rep(t, 4) {
		ll ny = y + dy[t], nx = x + dx[t];
		if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if(a[y][x] == a[ny][nx]) uf.unite(id(y, x), id(ny, nx));
	}
	vvll g(n);
	rep(y, h) rep(x, w) rep(t, 4) {
		ll ny = y + dy[t], nx = x + dx[t];
		if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if(!uf.issame(id(y, x), id(ny, nx))) {
			g[uf.find(id(y, x))].push_back(uf.find(id(ny, nx)));
			g[uf.find(id(ny, nx))].push_back(uf.find(id(y, x)));
		}
	}
	ll ans = 0;
	vll done(n);
	rep(y, h) rep(x, w) rep(t, 4) {
		ll ny = y + dy[t], nx = x + dx[t];
		if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		if(uf.issame(id(y, x), id(ny, nx))) continue;
		ll cur = uf.size(id(y, x)) + uf.size(id(ny, nx));
		cout << "cur: " << cur << endl;
		for(auto au : g[uf.find(id(y, x))]) {
			if(a[ny][nx] == a[au / w][au % w] & uf.find(au) != uf.find(id(ny, nx) && !done[uf.find(au)]))
			cur += uf.size(au);
			done[uf.find(au)] = true;
		}
		if(chmax(ans, cur)) cout << y << " " << x << "  " << ny << " " << nx << " : " << cur << endl;
		done.clear();
	}
	cout << ans << endl;
}