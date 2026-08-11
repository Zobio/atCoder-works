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

// ===== ここから問題固有の実装 =====

const int DX[4] = {-1, 1, 0, 0};
const int DY[4] = {0, 0, -1, 1};

struct GroupInfo
{
    ll s = 0, t = 0, p = 0, v = 0;
    double c = -1;        // コンパクト度（配置後に設定）
    vpll pos;              // 占有マスの座標（配置後に設定）
    bool active = false;  // 現在利用中かどうか
};

ll N;
vector<string> grid;
vvll owner; // owner[x][y]: 占有グループ番号。空きは-1。

double compactness(const vpll &region); // 前方宣言（find_regionから使うため）

constexpr ll CANDIDATE_COUNT = 30; // 開始点候補の数（方針C）。多いほど精度は上がるが計算コストも増える

// 指定した開始点から、「開始点からの距離(ユークリッド距離の2乗)が近い順」にpマス集める（方針A）。
// pマス集められれば座標リストを、集められなければ空のvpllを返す。
vpll try_region_from(pll start, ll p)
{
    ll x0 = start.first, y0 = start.second;
    auto dist2 = [&](ll x, ll y)
    { return (x - x0) * (x - x0) + (y - y0) * (y - y0); };

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    visited[x0][y0] = true;
    // {距離の2乗, {x, y}} を距離が小さい順に取り出す
    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<>> pq;
    pq.push({dist2(x0, y0), start});
    vpll region;

    while (!pq.empty() && (ll)region.size() < p)
    {
        auto [d0, pos] = pq.top();
        pq.pop();
        auto [x, y] = pos;
        region.push_back({x, y});
        rep(d, 4)
        {
            ll nx = x + DX[d], ny = y + DY[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (visited[nx][ny])
                continue;
            if (grid[nx][ny] != '.' || owner[nx][ny] != -1)
                continue;
            visited[nx][ny] = true;
            pq.push({dist2(nx, ny), {nx, ny}});
        }
    }
    if ((ll)region.size() == p)
        return region;
    return {};
}

// 空いている芝生マスから複数の開始点候補を選び、それぞれについてtry_region_fromを試す（方針C）。
// 成功した候補の中で最もコンパクト度が高いものを採用する。
// 1つも成功しなければ空のvpllを返す。
vpll find_region(ll p)
{
    // 現在空いている芝生マスを列挙する
    vpll empty_cells;
    rep(x, N)
    {
        rep(y, N)
        {
            if (grid[x][y] == '.' && owner[x][y] == -1)
                empty_cells.push_back({x, y});
        }
    }
    if (empty_cells.empty())
        return {};

    // 候補を間引いてサンプリングする
    // （先頭(idx=0)は従来の「左上から最初に見つけた空きマス」と同じなので、常に候補に含まれる＝従来より悪化はしない）
    vpll candidates;
    ll total = (ll)empty_cells.size();
    ll stride = max((ll)1, total / CANDIDATE_COUNT);
    for (ll idx = 0; idx < total && (ll)candidates.size() < CANDIDATE_COUNT; idx += stride)
        candidates.push_back(empty_cells[idx]);

    vpll best_region;
    double best_c = -1;
    for (auto &start : candidates)
    {
        vpll region = try_region_from(start, p);
        if (region.empty())
            continue;
        double c = compactness(region);
        if (c > best_c)
        {
            best_c = c;
            best_region = region;
        }
    }
    return best_region;
}


// コンパクト度 C = 4*sqrt(P) / L を計算する。
double compactness(const vpll &region)
{
    set<pll> cells(all(region));
    ll perimeter = 0;
    for (auto [x, y] : region)
    {
        rep(d, 4)
        {
            ll nx = x + DX[d], ny = y + DY[d];
            if (!cells.count({nx, ny}))
                perimeter++;
        }
    }
    return 4.0 * sqrt((double)region.size()) / perimeter;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll M;
    double R;
    in(N, M, R);

    // VECマクロだとvector<string>用のoperator>>解決でコンパイルエラーになるため、
    // ここだけ通常のループで読み込む
    vector<string> grid_in(N);
    rep(i, N) cin >> grid_in[i];
    grid = grid_in;

    vv(ll, owner_in, N, N, -1);
    owner = owner_in;

    vector<GroupInfo> groups(M);

    // ===== 受け入れ判断用の閾値・統計（すべて経験的な仮の値。要調整） =====
    constexpr double COMPACT_THRESHOLD = 0.5; // これより歪んだ形は断る
    constexpr double DENSITY_FACTOR = 0.6;    // 平均の「単位面積・単位時間あたりの価値」のこの割合未満なら断る
    constexpr ll WARMUP = 20;                 // 最初のWARMUP件は統計不足なので密度チェックをスキップする
    double density_sum = 0;                   // これまで見た(V/P)の合計
    ll density_count = 0;                     // これまで見たグループ数

    rep(i, M)
    {
        ll gi, s, t, p, v;
        in(gi, s, t, p, v);
        groups[i].s = s;
        groups[i].t = t;
        groups[i].p = p;
        groups[i].v = v;

        // 退去時刻が現在時刻sより前のグループを解放する
        rep(j, i)
        {
            if (groups[j].active && groups[j].t < s)
            {
                for (auto [x, y] : groups[j].pos)
                    owner[x][y] = -1;
                groups[j].active = false;
            }
        }

        // 移動は行わない
        cout << 0 << ln;

        vpll region = find_region(p);
        bool accept = false;
        double c = -1;
        // 単位面積・単位時間あたりの価値。長く占有するグループほど機会損失が大きいことを考慮する。
        double density = (double)v / ((double)p * (double)(t - s));
        if (!region.empty())
        {
            c = compactness(region);
            double avg_density = density_count > 0 ? density_sum / density_count : density;
            bool density_ok = (density_count < WARMUP) || (density >= avg_density * DENSITY_FACTOR);
            bool compact_ok = (c >= COMPACT_THRESHOLD);
            accept = density_ok && compact_ok;
        }

        // 統計は受け入れたかどうかに関わらず全グループについて更新する
        // （「今後来るグループの典型的な価値密度」を推定するための材料にするため）
        density_sum += density;
        density_count++;

        if (accept)
        {
            // 割り当てる: ownerを更新し、コンパクト度と占有マスを記録する
            for (auto [x, y] : region)
                owner[x][y] = i;
            groups[i].pos = region;
            groups[i].c = c;
            groups[i].active = true;
            cout << "Yes" << ln;
            for (auto [x, y] : region)
                cout << x << " " << y << ln;
        }
        else
        {
            // 拒否（置けなかった場合／条件を満たさなかった場合の両方）
            cout << "No" << ln;
        }
        cout.flush();
    }
    return 0;
}