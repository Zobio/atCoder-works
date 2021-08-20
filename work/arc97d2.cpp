#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 1LL << 60


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
    } else {
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
	int n, m; cin >> n >> m;
	vector<int> p(n);
	map<int, int> mp;
	rep(i, n) cin >> p[i], p[i]--, mp[p[i]] = i;
	UnionFind uf(n);
	rep(i, m) {
		int x, y; cin >> x >> y; x--; y--;
		uf.unite(x, y);
	}
	int ans = 0;
	rep(i, n) {
		if(uf.find(mp[i]) == uf.find(i)) ans++;
	}
	cout << ans << endl;
}