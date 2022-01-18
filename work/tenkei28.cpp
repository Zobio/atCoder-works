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
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 1000000007LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
    ll n; cin >> n;
    vvll imos_tate(1010), imos_yoko(1010);
    rep(i, n) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        imos_tate[a]++; imos_yoko[b]++; imos_tate[c]--; imos_tate[d]--;
        imos[a][b]++; imos[c + 1][d + 1]--;
    }
    vvll rui(1010, vll(1010));
    vll ans(n + 1); //仮想配列
    rep(i, 1001){ 
    ll now = 0;
        rep(j, 1001) {
            now += imos[i][j];
            rui[i][j + 1] = rui[i][j] + now;
        }
    }
    rep(i, 10) {rep(j, 10) cout << rui[i][j] << " "; cout << endl;}
    rep(i, 1001){ 
    ll now = 0;
        rep(j, 1001) {
            now += imos[j][i];
            rui[j + 1][i] = rui[j][i] + now;
        }
    }
    rep(i, 10) {rep(j, 10) cout << rui[i][j] << " "; cout << endl;}
}