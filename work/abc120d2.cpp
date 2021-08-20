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
	ll n, m; cin >> n >> m;
	UnionFind uf(n);
	vector<ll> a(m), b(m);
	rep(i, m) cin >> a[i] >> b[i], a[i]--, b[i]--;
	vector<ll> ans(m); ans[m - 1] = n * (n - 1) / 2;
	for(int i = m - 1; i > 0; i--) {
		if(uf.find(a[i]) == uf.find(b[i])) ans[i - 1] = ans[i];
		else ans[i - 1] = ans[i] - uf.size(a[i]) * uf.size(b[i]); //連結させたときの変化はa * b
		uf.unite(a[i], b[i]);
	}
	rep(i, m) cout << ans[i] << endl;
}