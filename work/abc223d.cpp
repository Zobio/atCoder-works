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
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

struct UnionFind {
	ll groups;
	vector<ll> parents;

	UnionFind(ll n) {
		groups = n;
		parents = vector<ll>(n, -1);
	}

	ll find(ll x) {
		if (parents.at(x) < 0) {
			return x;
		}else{
			parents[x] = find(parents[x]);
			return parents[x];
		}
	}

	void unite(ll x, ll y) {
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

	ll size(ll x) {
		return -parents[find(x)];
	}

	bool issame(ll x, ll y) {
		return find(x) == find(y);
	}

	vector<ll> roots() {
		vector<ll> ret;
		for (ll i = 0; i < parents.size(); i++)
			if (parents[i] < 0)
				ret.push_back(i);
		return ret;
	}

	ll group_count() {
		return groups;
	}
};

int main() {
	ll n, m; cin >> n >> m;
	deque<ll> d; rep(i, n) d.push_back(i + 1);
	vector<pair<ll, ll>> ab(m);
	UnionFind uf(n);
	rep(i, m) {
		ll a, b; cin >> a >> b;
		ab[i] = {a, b};
		uf.unite(a, b);
	}
	rep(i, m) {
		ll a = ab[i].first, b = ab[i].second;
		if(a < b && mp[{b, a}] == false) continue;
		else if(a < b && mp[{b, a}] == true) {cout << -1 << endl; return 0;}
	}
}