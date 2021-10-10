#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 1000000007LL
#define INF 1LL << 60
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
    for(ll i = 0; i < a.size(); i++) {
        res.at(i) = lower_bound(b.begin(), b.end(), a.at(i)) - b.begin();
    }
    a = res;
}

template<typename VV>
void rotate_90(VV& a) {
    /*2次元グリッドを反時計回りに90°回転させる関数 (2回回せば逆さまになる)
    (例)
    000     011
    001 --> 000
    101     001
    注意 : 縦と横のサイズが同じでないとバグる
    */
    size_t siz = a.size();
    VV b(siz);
    for(size_t i = 0; i < siz; i++) for(size_t j = 0; j < siz; j++) b[i].push_back(a[j][siz - i - 1]);
    a = b;
}

int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cout << a[i] << " "; cout << endl;
    shrink_coordinates(a);
    rep(i, n) cout << a[i] << " "; cout << endl;
}