#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
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
	vector<pair<ll, pair<ll, ll>>> br(m);
	rep(i, m) {
		ll a, b, y; cin >> a >> b >> y; a--; b--; y--;
		br.at(i) = make_pair(y, make_pair(a, b));
	}
	sort(br.rbegin(), br.rend());
	ll q; cin >> q;
	vector<pair<ll, pair<ll, ll>>> pe(q);
	rep(i, q) {
		ll v, w; cin >> v >> w; v--; w--;
		pe.at(i) = make_pair(w, make_pair(v, i));
	}
	sort(pe.rbegin(), pe.rend());
	vector<ll> ans(q);
	UnionFind uf(n);
	auto it = br.begin();
	for(auto a : pe) {
		while(it -> first > a.first) {
			if(it == br.end()) break;
			uf.unite(it -> second.first, it -> second.second);
			it++;
		}
		ans[a.second.second] = uf.size(a.second.first);
	}
	rep(i, q) cout << ans[i] << endl;
}