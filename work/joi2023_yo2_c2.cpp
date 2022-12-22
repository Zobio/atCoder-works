#include <bits/stdc++.h>
//#include <atcoder/all> // AtCoder
using namespace std;
//using namespace atcoder; // AtCoder
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
//using mint = modint998244353; // AtCoder
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
#define overload2(_1, _2, name, ...) name
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(n) for (ll i = 0; i < n; i++)
#define rep2(i, n) for (ll i = 0; i < n; i++)
#define rep3(i, a, b) for (ll i = a; i < b; i++)
#define rep4(i, a, b, c) for (ll i = a; i < b; i += c)
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define reps1(n) for (ll i = 1; i <= n; i++)
#define reps2(i, n) for (ll i = 1; i <= n; i++)
#define reps(...) overload2(__VA_ARGS__, reps2, reps1)(__VA_ARGS__)
#define rrep1(n) for (int i = n - 1; i >= 0; i--)
#define rrep2(i, n) for (int i = n - 1; i >= 0; i--)
#define rrep3(i, a, b) for (int i = b - 1; i >= a; i--)
#define rrep4(i, a, b, c) for (int i = b - 1; i >= a; i -= c)
#define rrep(...) overload4(__VA_ARGS__,rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define rreps1(n) for (long long i = n; i >= 1; i--)
#define rreps2(i, n) for (long long i = n; i >= 1; i--)
#define rreps(...) overload2(__VA_ARGS__, rreps2, rreps1)(__VA_ARGS__)
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

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p);

template <class T1, class T2>
istream &operator>>(istream &is, pair<T1, T2> &p);

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v);

template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v);

template <class T>
ostream &operator<<(ostream &os, const vector<vector<vector<T>>> &v);

template <class T>
istream &operator>>(istream &is, vector<T> &v);

template <class T, class S>
ostream &operator<<(ostream &os, const map<T, S> &mp);

template <class T>
ostream &operator<<(ostream &os, const set<T> &st);

template <class T>
ostream &operator<<(ostream &os, const multiset<T> &st);

template <class T>
ostream &operator<<(ostream &os, queue<T> q);

template <class T>
ostream &operator<<(ostream &os, deque<T> q);

template <class T>
ostream &operator<<(ostream &os, stack<T> st);

template <class T, class Container, class Compare>
ostream &operator<<(ostream &os, priority_queue<T, Container, Compare> pq);

//ostream &operator<<(ostream &os, const mint &i); //atcoder

//ostream &operator<<(ostream &os, const vector<mint> &v); //atcoder

//ostream &operator<<(ostream &os, const modint &i); //atcoder

//ostream &operator<<(ostream &os, const vector<modint> &v); //atcoder

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
	os << "(" << p.first << "," << p.second << ")";
	return os;
}

template <class T1, class T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
	is >> p.first >> p.second;
	return is;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
	for (int i = 0; i < (int)v.size(); i++) {
		os << v[i] << (i + 1 != (int)v.size() ? " " : "");
	}
	return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
	for (int i = 0; i < (int)v.size(); i++) {
		os << v[i] << endl;
	}
	return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<vector<vector<T>>> &v) {
	for (int i = 0; i < (int)v.size(); i++) {
		os << "i = " << i << endl;
		os << v[i];
	}
	return os;
}

template <class T>
istream &operator>>(istream &is, vector<T> &v) {
	for (T &in : v) {
		is >> in;
	}
	return is;
}

template <class T, class S>
ostream &operator<<(ostream &os, const map<T, S> &mp) {
	for (auto &[key, val] : mp) {
		os << key << ": " << val << "";
	}
	return os;
}

template <class T>
ostream &operator<<(ostream &os, const set<T> &st) {
	auto itr = st.begin();
	for (int i = 0; i < (int)st.size(); i++) {
		os << *itr << (i + 1 != (int)st.size() ? " " : "");
		itr++;
	}
	return os;
}

template <class T>
ostream &operator<<(ostream &os, const multiset<T> &st) {
	auto itr = st.begin();
	for (int i = 0; i < (int)st.size(); i++) {
		os << *itr << (i + 1 != (int)st.size() ? " " : "");
		itr++;
	}
	return os;
}

template <class T>
ostream &operator<<(ostream &os, queue<T> q) {
	while (q.size()) {
		os << q.front() << " ";
		q.pop();
	}
	return os;
}

template <class T>
ostream &operator<<(ostream &os, deque<T> q) {
	while (q.size()) {
		os << q.front() << "";
		q.pop_front();
	}
	return os;
}

template <class T>
ostream &operator<<(ostream &os, stack<T> st) {
	while (st.size()) {
		os << st.top() << "";
		st.pop();
	}
	return os;
}

template <class T, class Container, class Compare>
ostream &operator<<(ostream &os, priority_queue<T, Container, Compare> pq) {
	while (pq.size()) {
		os << pq.top() << "";
		pq.pop();
	}
	return os;
}

/*ostream &operator<<(ostream &os, const mint &i) { //AtCoder
	os << i.val();
	return os;
}*/

/*ostream &operator<<(ostream &os, const vector<mint> &v) { //AtCoder
	for (int i = 0; i < (int)v.size(); i++) {
		os << v[i].val() << (i + 1 != (int)v.size() ? " " : "");
	}
	return os;
}*/

/*ostream &operator<<(ostream &os, const modint &i) { //AtCoder
	os << i.val();
	return os;
}*/

/*ostream &operator<<(ostream &os, const vector<modint> &v) { //AtCoder
	for (int i = 0; i < (int)v.size(); i++) {
		os << v[i].val() << (i + 1 != (int)v.size() ? "" : "");
	}
	return os;
}*/

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

const vll dy = {0, 1, 0, -1};
const vll dx = {1, 0, -1, 0};

int main() {
	ll h, w; cin >> h >> w;

	auto id = [&] (ll i, ll j) {
		return i * w + j;
	};

	vvll a(h, vll(w));
	UnionFind uf(h * w);

	rep(i, h) rep(j, w) {
		cin >> a[i][j];
		if(i && a[i][j] == a[i - 1][j]) uf.unite(id(i, j), id(i - 1, j));
		if(j && a[i][j] == a[i][j - 1]) uf.unite(id(i, j), id(i, j - 1));
	}

	vector<map<ll, set<ll>>> cand(h * w); //"グループの親"の"隣接頂点の色"ごとの頂点集合

	rep(y, h) rep(x, w) {
		rep(i, 4) {
			ll ny = y + dy[i], nx = x + dx[i];
			if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			cand[uf.find(id(y, x))][a[ny][nx]].insert(id(ny, nx)); //[親番号][色] = 隣の頂点
		}
	}

	ll ans = 0;
	rep(y, h) rep(x, w) {
		chmax(ans, uf.size(id(y, x)));
		for(auto [color, b] : cand[id(y, x)]) { //色、頂点集合
			ll cur = uf.size(id(y, x));
			vector<bool> united(h * w);
			united[id(y, x)] = true;
			for(auto nxt : b) {
				if(united[uf.find(nxt)]) continue;
				cur += uf.size(nxt);
				united[uf.find(nxt)] = true;
			}
			chmax(ans, cur);
		}
	}

	cout << ans << endl;
}