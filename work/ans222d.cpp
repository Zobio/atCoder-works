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
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll N;
ll a[3010], b[3010];
ll dp[3010][3010];
ll rui[3010];
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> N;
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];

    dp[0][0] = 1;
    rep(i, N) {
        rui[0] = dp[i][0];
        rep(lst, 3000) rui[lst + 1] = (rui[lst] + dp[i][lst]) % MOD;
        for(ll nxt = a[i]; nxt <= b[i]; nxt++) dp[i + 1][nxt] = (dp[i + 1][nxt] + rui[nxt]) % MOD;
    }
    
    ll ans = 0;
    rep(lst, 3001) ans += dp[N][lst];
    cout << ans << endl;
}