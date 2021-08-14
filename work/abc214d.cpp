#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

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
	int n;
	cin >> n;
	vector<tuple<int, int, int>> edge(n - 1);
	rep(i, n - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		edge.at(i) = make_tuple(c, a, b); 
	}
	sort(edge.begin(), edge.end());
	ll ans = 0;
	UnionFind uf(n);
	for(int i = 0; i < n - 1; i++) {
		ans += get<0>(edge[i]) * uf.size(get<1>(edge[i])) * uf.size(get<2>(edge[i]));
		uf.unite(get<1>(edge[i]), get<2>(edge[i]));
	}
	cout << ans << endl;
}