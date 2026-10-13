#include <bits/stdc++.h>
// #include <atcoder/all> // AtCoder
using namespace std;
// using namespace atcoder; // AtCoder
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
// using mint = modint998244353; // AtCoder
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vvvll = vector<vector<vector<long long>>>;
using vvvvll = vector<vector<vector<vector<long long>>>>;
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
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
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
#define MINUS printf("-1\n"), exit(0)
#define cuot cout // typo
#define endk endl // typo
constexpr char ln = '\n';
constexpr long long MOD = 998244353LL;
constexpr long long LINF = 0x1fffffffffffffff; // 4倍までOK 10^18より大きい
constexpr int INF = 0x3fffffff;				   // 2倍までOK 10^9より大きい
template <class T>
void setcout(T n) { cout << setprecision(n) << fixed; }
template <class... T>
constexpr auto min(T... a) { return min(initializer_list<common_type_t<T...>>{a...}); }
template <class... T>
constexpr auto max(T... a) { return max(initializer_list<common_type_t<T...>>{a...}); }
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
long long acc(const T &a) { return accumulate(all(a), 0LL); }
template <class T>
long double accl(const T &a) { return accumulate(all(a), 0.0L); }
template <class T>
vector<T> mrui(const vector<T> &a)
{
    vector<T> ret(a.size() + 1);
    for (int i = 0; i < a.size(); i++)
    {
        ret[i + 1] = ret[i] + a[i];
    }
    return ret;
}
template <class T>
vector<vector<T>> mrui2(const vector<vector<T>> &a)
{
    vector<vector<T>> ret(a.size() + 1, vector<T>(a.front().size() + 1));
    for (int i = 0; i < (int)a.size(); i++)
    {
        for (int j = 0; j < (int)a.front().size(); j++)
        {
            ret[i + 1][j + 1] = ret[i][j + 1] + ret[i + 1][j] - ret[i][j] + a[i][j];
        }
    }
    return ret;
}
template <class T>
vector<T> kaisa(const vector<T> &a)
{
    vector<T> ret(a.size() - 1);
    for (int i = 0; i < a.size() - 1; i++)
    {
        ret[i] = a[i + 1] - a[i];
    }
    return ret;
}

inline void in() {}
template <class Head, class... Tail>
inline void in(Head &head, Tail &...tail)
{
    cin >> head;
    in(tail...);
}

#define INT(...)     \
    int __VA_ARGS__; \
    in(__VA_ARGS__)
#define LL(...)     \
    ll __VA_ARGS__; \
    in(__VA_ARGS__)
#define ULL(...)     \
    ull __VA_ARGS__; \
    in(__VA_ARGS__)
#define STR(...)        \
    string __VA_ARGS__; \
    in(__VA_ARGS__)
#define CHR(...)      \
    char __VA_ARGS__; \
    in(__VA_ARGS__)
#define DBL(...)        \
    double __VA_ARGS__; \
    in(__VA_ARGS__)
#define LD(...)     \
    ld __VA_ARGS__; \
    in(__VA_ARGS__)
#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size) \
    vector<type> name(size);  \
    in(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, ...)                               \
    vector<vector<type>> name(h, vector<type>(__VA_ARGS__)); \
    in(name)
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T1, class T2>
istream &operator>>(istream &is, pair<T1, T2> &p)
{
    is >> p.first >> p.second;
    return is;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 != (int)v.size() ? " " : "");
    }
    return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << endl;
    }
    return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<vector<vector<T>>> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << "i = " << i << endl;
        os << v[i];
    }
    return os;
}

template <class T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
    {
        is >> in;
    }
    return is;
}

template <class T>
ostream &operator<<(ostream &os, const deque<T> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 != (int)v.size() ? " " : "");
    }
    return os;
}

template <class T>
ostream &operator<<(ostream &os, const deque<deque<T>> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << endl;
    }
    return os;
}

template <class T>
ostream &operator<<(ostream &os, const deque<deque<deque<T>>> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << "i = " << i << endl;
        os << v[i];
    }
    return os;
}

template <class T>
istream &operator>>(istream &is, deque<T> &v)
{
    for (T &in : v)
    {
        is >> in;
    }
    return is;
}

template <class T, class S>
ostream &operator<<(ostream &os, const map<T, S> &mp)
{
    for (auto &[key, val] : mp)
    {
        os << key << ": " << val << " ";
    }
    return os;
}

template <class T>
ostream &operator<<(ostream &os, const set<T> &st)
{
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++)
    {
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}

template <class T>
ostream &operator<<(ostream &os, const multiset<T> &st)
{
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++)
    {
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}

template <class T>
ostream &operator<<(ostream &os, queue<T> q)
{
    while (q.size())
    {
        os << q.front() << " ";
        q.pop();
    }
    return os;
}

template <class T>
ostream &operator<<(ostream &os, deque<T> q)
{
    while (q.size())
    {
        os << q.front() << " ";
        q.pop_front();
    }
    return os;
}

template <class T>
ostream &operator<<(ostream &os, stack<T> st)
{
    while (st.size())
    {
        os << st.top() << " ";
        st.pop();
    }
    return os;
}

template <class T, class Container, class Compare>
ostream &operator<<(ostream &os, priority_queue<T, Container, Compare> pq)
{
    while (pq.size())
    {
        os << pq.top() << " ";
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

// テンプレート部分は省略（貼ってもらったものをそのまま使用）

struct EulerTour
{
    ll n;
    vvll g;
    vll tour;          // 訪問順の頂点列（長さ 2N-1）
    vll in, out, dep;  // in[v]/out[v]: tour 上で v が最初/最後に現れる位置, dep[v]: 深さ
    vvll sp;           // LCA 用 Sparse Table（tour 上の添字を持つ）

    EulerTour(ll n) : n(n), g(n), in(n), out(n), dep(n) {}

    void add_edge(ll u, ll v)
    {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void build(ll root = 0)
    {
        tour.clear();
        vll par(n, -1), idx(n, 0);
        stack<ll> st;
        st.push(root);
        dep[root] = 0;
        in[root] = 0;
        tour.push_back(root);
        while (st.size())
        {
            ll v = st.top();
            if (idx[v] < (ll)g[v].size())
            {
                ll to = g[v][idx[v]++];
                if (to == par[v]) continue;
                par[to] = v;
                dep[to] = dep[v] + 1;
                in[to] = tour.size();
                tour.push_back(to);
                st.push(to);
            }
            else
            {
                out[v] = (ll)tour.size() - 1;
                st.pop();
                if (st.size()) tour.push_back(st.top()); // 親に戻る
            }
        }
        build_lca();
    }

    // tour 上の区間で深さ最小の頂点 = LCA
    void build_lca()
    {
        ll m = tour.size();
        ll lg = 1;
        while ((1LL << lg) < m) lg++;
        sp.assign(lg + 1, vll(m));
        rep(i, m) sp[0][i] = i;
        reps(k, lg)
        {
            for (ll i = 0; i + (1LL << k) <= m; i++)
            {
                ll a = sp[k - 1][i], b = sp[k - 1][i + (1LL << (k - 1))];
                sp[k][i] = (dep[tour[a]] < dep[tour[b]] ? a : b);
            }
        }
    }

    ll lca(ll u, ll v)
    {
        ll l = min(in[u], in[v]), r = max(in[u], in[v]) + 1; // [l, r)
        ll k = 63 - __builtin_clzll(r - l);
        ll a = sp[k][l], b = sp[k][r - (1LL << k)];
        return tour[dep[tour[a]] < dep[tour[b]] ? a : b];
    }

    ll dist(ll u, ll v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }

    // u が v の部分木に含まれるか
    bool in_subtree(ll v, ll u) { return in[v] <= in[u] && in[u] <= out[v]; }
};

// テンプレート・EulerTour 部分はそのまま

int main() {
    ll n; cin >> n;
    vll a(n - 1), b(n - 1);
    EulerTour et(n);
    rep(i, n - 1) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        et.add_edge(a[i], b[i]);
    }
    et.build(0);

    ll m = et.tour.size();
    vll imos(m + 1, 0);
    // tour の区間 [l, r] に x を加算
    auto add = [&](ll l, ll r, ll x) {
        imos[l] += x;
        imos[r + 1] -= x;
    };

    rep(i, n - 1) {
        ll w = i + 1; // 辺の番号（1-indexed）が加算する値
        // 深いほうが子
        ll c = (et.dep[a[i]] > et.dep[b[i]] ? a[i] : b[i]);
        // 部分木の頂点数 k は、tour 上の区間の長さが 2k-1 になることから求める
        ll sz = (et.out[c] - et.in[c] + 2) / 2;

        if (sz * 2 > n) {
            // c の部分木のほうが大きい
            add(et.in[c], et.out[c], w);
        } else {
            // それ以外のほうが大きい: 全体に足して、部分木から引く
            add(0, m - 1, w);
            add(et.in[c], et.out[c], -w);
        }
    }

    rep(i, 1, m) imos[i] += imos[i - 1];

    vll ans(n);
    rep(u, n) ans[u] = imos[et.in[u]];
    cout << ans << ln;
}