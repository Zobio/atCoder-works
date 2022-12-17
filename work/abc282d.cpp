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

ll n, m;
vvll g;
vll color;
bool nibu = true;

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

void dfs(ll cur, ll c) {
	color[cur] = c;
	for(auto nxt : g[cur]) {
		if(color[nxt] == c) nibu = false;
		if(color[nxt] == -1) {
			dfs(nxt, !c);
		}
	}
}

int main() {
	cin >> n >> m;
	g.resize(n);
	color.resize(n, -1);
	UnionFind uf(n);
	rep(i, m) {
		ll a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
		uf.unite(a, b);
	}
	rep(i, n) {
		if(color[i] == -1) dfs(i, 0);
	}
	if(!nibu) cout << 0 << endl, exit(0);
	ll ans = 0;
	vvvll g_cl(n, vvll(2));
	rep(i, n) g_cl[uf.find(i)][color[i]].push_back(i);
	rep(i, n) {
		ll fix1 = g[i].size(); //already connected
		ll fix2 = g_cl[uf.find(i)][color[i]].size(); //same color
		ans += n - fix1 - fix2;
	}
	cout << ans  / 2 << endl;
}