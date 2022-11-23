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

int N, M, A[101010], B[101010];
//---------------------------------------------------------------------------------------------------
int naive() {
    int ans = 0;
    
    rep(x, 1, M + 1) {
        bool ok = true;
        rep(i, 0, N) {
            if (x % B[i] != 0) ok = false;
            if ((x / B[i]) % 2 == 0) ok = false;
        }
        if (ok) {
            printf(">> %d\n", x);
            ans++;
        }
    }

    return ans;
}
//---------------------------------------------------------------------------------------------------
int solve() {
    ll lc = 1;
    rep(i, 0, N) lc = lcm(lc, B[i]);

    rep(i, 0, N) if ((lc / B[i]) % 2 == 0) return 0;

    ll ans = M / lc;
    ans = (ans + 1) / 2;
    return ans;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) B[i] = A[i] / 2;

    //cout << naive() << endl;
    cout << solve() << endl;
}