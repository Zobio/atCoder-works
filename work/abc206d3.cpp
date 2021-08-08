#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(a) cout << a << endl

struct UnionFind
{
	ll groups;
	vector<ll> parents;

	UnionFind(ll n)
	{
		groups = n;
		parents = vector<ll>(n, -1);
	}

	ll find(ll x)
	{
		if (parents.at(x) < 0)
		{
			return x;
		}
		else
		{
			parents[x] = find(parents[x]);
			return parents[x];
		}
	}

	void unite(ll x, ll y)
	{
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

	ll size(ll x)
	{
		return -parents[find(x)];
	}

	bool issame(ll x, ll y)
	{
		return find(x) == find(y);
	}

	vector<ll> roots()
	{
		vector<ll> ret;
		for (ll i = 0; i < parents.size(); i++)
			if (parents[i] < 0)
				ret.push_back(i);
		return ret;
	}

	ll group_count()
	{
		return groups;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a.at(i);
	UnionFind uf(200001);
	for(int i = 0, j = n - 1; i < j; i++, j--) {
		uf.unite(--a[i], --a[j]);
	}
	ll ans = 0;
	rep(i, 200001) {
		if(uf.find(i) != i) continue;
		ans += uf.size(i) - 1;
	}
	cout << ans << endl;
}