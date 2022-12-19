#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
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
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define reep(i, a, b) for (long long i = a; i < b; i++)
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
istream &operator>>(istream &is, const vector<T> &v) {
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


int main() {
    ll q; cin >> q;
    rep(_, q) {
        ll n, k; cin >> n >> k;
        priority_queue<pll, vpll, greater<pll>> pq; //(attack, HP)
        vll t1(n), t2(n);
        rep(i, n) cin >> t1[i];
        rep(i, n) cin >> t2[i];
        rep(i, n) pq.push({t2[i], t1[i]});
        ll d = 0; //累積ダメージ
        bool flag = false;
        while(pq.size()) {
            d += k;
            while(pq.size() && pq.top().second <= d) pq.pop();
            pll cur = pq.top();
            k -= cur.first;
            if(k <= 0 && pq.size()) {cout << "NO" << endl; flag = true; break;}
        }
        if(!flag && pq.empty()) cout << "YES" << endl;
    }
}