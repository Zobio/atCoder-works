#include <bits/stdc++.h>
using namespace std;
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
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << a.at(i).at(j); cout << endl;}
#define setcout(n) cout << setprecision(n) << fixed
#define YESS {printf("Yes\n"); return 0;}
#define NOO {printf("No\n"); return 0;}
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
    ll ma = 100010;
    ll w, d, h, c; cin >> w >> d >> h >> c; //幅、奥行、高さ、削る回数
    map<ll, ll> dep;
    rep(i, c) {
        ll x, y, z; cin >> x >> y >> z; 
        dep[x * ma + y] += z;
    }
    ll ans = 2 * w * d; //上と下
    rep(i, w) { //横方向
        ll fix = 0;
        if(dep.lower_bound(i * ma + 0) != dep.upper_bound(i * ma + 0)) fix += dep[i * ma + 0]; //奥 横方向
        if(dep.lower_bound(i * ma + d - 1) != dep.upper_bound(i * ma + d - 1)) fix += dep[i * ma + d - 1]; //手前 横方向
        ans += 2 * h - fix;
    }
    rep(i, d) { //奥方向
        ll fix = 0;
        if(dep.lower_bound(0 * ma + i) != dep.upper_bound(0 * ma + i)) fix += dep[0 * ma + i]; //左方向
        if(dep.lower_bound((w - 1) * ma + i) != dep.upper_bound((w - 1) * ma + i)) fix += dep[(w - 1) * ma + i]; //右方向
        ans += 2 * h - fix;
    }
    for(auto cur : dep) {
        ll x = cur.first / ma, y = cur.first % ma;
        for(auto dx : {-1, 0, 1}) for(auto dy : {-1, 0, 1}) {
            if((dx == 0) + (dy == 0) != 1) continue;
            ll nx = x + dx, ny = y + dy;
            if(nx < 0 || nx >= w || ny < 0 || ny >= d) continue;
            ll hi = dep.lower_bound(nx * ma + ny) != dep.upper_bound(nx * ma + ny) ? dep[nx * ma + ny] : 0;
            ll diff = dep[x * ma + y] - hi;
            if(diff < 0) diff = 0; //二重計算しない
            ans += diff;
        }
    }
    cout << ans << endl;
}