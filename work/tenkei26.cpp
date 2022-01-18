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

vvll g;
vll col;

void dfs(ll cur, ll c) {
    col[cur] = c;
    for(auto au : g[cur]) {
        if(col[au] == -1) dfs(au, 1 - c);
    }
}

int main() {
	ll n; cin >> n;
    g.resize(n); col.resize(n, -1);
    rep(i, n - 1) {
        ll a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, 0);
    vll ans1, ans2;
    rep(i, n) {if(col[i]) ans1.push_back(i); else ans2.push_back(i);}
    if(ans1.size() >= ans2.size()) {rep(i, n / 2) cout << ans1[i] + 1 << " "; cout << endl;}
    else {rep(i, n / 2) cout << ans2[i] + 1 << " "; cout << endl;}
}