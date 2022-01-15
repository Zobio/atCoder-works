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
#define INF (1LL << 60)
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

struct edge{ll u, v, cost;};

bool comp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}

int main() {
	ll MA = 200100;
	ll n, m, q; cin >> n >> m >> q;
	vector<edge> es;
	rep(i, m) {
		ll a, b, c; cin >> a >> b >> c; a--; b--;
		if(a == b) continue;
		edge e; e.u = min(a, b); e.v = max(a, b); e.cost = c;
		es.push_back(e);
	}
	sort(all(es), comp);
	vector<UnionFind> vu;
	UnionFind uf(MA);
	vll c;
	vu.push_back(uf); //まだ素集合の要素数==n
	rep(i, m) {
		edge e = es.at(i);
		if(uf.find(e.u) != uf.find(e.v)) {
			uf.unite(e.u, e.v);
			vu.push_back(uf);
			c.push_back(e.cost);
		}
	}
	rep(i, q) {
		ll u, v, w; cin >> u >> v >> w; u--; v--;
		ll p = lower_bound(all(c), w) - c.begin();
		cout << p << endl;
		if(p >= vu.size()) cout << "No" << endl;
		else if(vu.at(p).find(u) != vu.at(p).find(v)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}