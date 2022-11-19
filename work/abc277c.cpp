#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define reep(i, a, b) for(long long i = a; i < b; i++)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define dll deque<long long>
#define ddll deque<dque<long long>>
#define dddll deque<deque<deque<long long>>>
#define ddddll deque<deque<deque<deque<long long>>>>
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;}
#define setcout(n) cout << setprecision(n) << fixed
#define YESS {printf("Yes\n"); return 0;}
#define NOO {printf("No\n"); return 0;}
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define mint modint998244353
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

template<typename V>
void shrink_coordinates(V& a) {
	/*
	座標圧縮を行う関数
	(例)
	{6, 9, 9, 2, 100} -->  {1, 2, 2, 0, 3}
	*/
	V b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	V res(a.size());
	for(long long i = 0; i < a.size(); i++) {
		res.at(i) = lower_bound(b.begin(), b.end(), a.at(i)) - b.begin();
	}
	a = res;
}

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

int main() {
	ll n; cin >> n;
	vll a(n), b(n), ab;
	rep(i, n) {
		cin >> a[i] >> b[i]; a[i]--; b[i]--;
	}
	a.push_back(0); b.push_back(0); n++;
	rep(i, n) ab.push_back(a[i]);
	rep(i, n) ab.push_back(b[i]);
	shrink_coordinates(ab);
	map<ll, ll> m1, m2;
	rep(i, n * 2) {
		m1[ab[i]] =  i < n ? a[i] : b[i - n];
		m2[i < n ? a[i] : b[i - n]] = ab[i];
	}
	UnionFind uf(n * 2);
	rep(i, n) {
		uf.unite(m2[a[i]], m2[b[i]]);
	}
	ll t = 0;
	rep(i, n * 2) if(uf.issame(i, 0)) t = i;
	cout << m1[t] + 1 << endl;
}