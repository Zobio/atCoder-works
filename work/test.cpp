#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int N;
ll K, A[101010];
ll dp[61][2]; // dp[dgt][isless]
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K;
    rep(i, 0, N) cin >> A[i];
 
    rep(dgt, 0, 61) rep(isless, 0, 2) dp[dgt][isless] = -infl;
    dp[0][0] = 0;
 
    rep(dgt, 0, 60) rep(isless, 0, 2) if(0 <= dp[dgt][isless]) {
        int d = 59 - dgt;
        ll msk = 1LL << d;
 
        int zero = 0, one = 0;
        rep(i, 0, N) {
            if (A[i] & msk) one++;
            else zero++;
        }
 
        // 0
        int isless2 = isless;
        if (K & msk) isless2 = 1;
        chmax(dp[dgt + 1][isless2], dp[dgt][isless] + one * msk);
 
        // 1
        if ((K & msk) or isless == 1) {
            chmax(dp[dgt + 1][isless], dp[dgt][isless] + zero * msk);
        }
    }
 
    cout << max(dp[60][0], dp[60][1]) << endl;
}