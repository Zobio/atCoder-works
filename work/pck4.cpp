#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define vll vector<ll>

struct UnionFind {
	ll gs;
	vll pts;

	UnionFind(ll n) {gs = n; pts = vll(n, -1);};

	ll find(ll x) {
		if(pts[x] < 0) return x;
		else {pts[x] = find(pts[x]); return pts[x];}
	}

	void unite(ll x, ll y) {
		x = find(x); y = find(y);
		if(x == y) return;
		gs--;
		if(pts[x] > pts[y]) swap(x, y);
		pts[x] += pts[y];
		pts[y] = x;
	}

	ll size(ll x) {return -pts[find(x)];}

	bool issame(ll x, ll y) {return find(x) == find(y);};

	vll roots() {
		vll ret;
		rep(i, pts.size()) {
			if(pts[i] < 0) ret.push_back(i);
		}
		return ret;
	}

	ll group_count() {
		return gs;
	}
};

int main() {
	ll n; cin >> n;
	ll cnt = 0;
	UnionFind uf(n);
	rep(i, n) {
		ll t; cin >> t;
		if(t) uf.unite(i, (i + 1) % n);
	}
	cout << uf.group_count() << endl;
}