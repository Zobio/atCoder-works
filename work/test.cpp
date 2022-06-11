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

int N, A[101010], B[101010];
//---------------------------------------------------------------------------------------------------
ll get() {
    ll sm = 0;
    rep(i, 0, N - 1) sm += abs(B[i + 1] - B[i]);
    return sm;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    sort(A, A + N);
 
    ll ans = -1;
    if (N % 2 == 0) {
        rep(i, 0, N / 2) B[i * 2 + 1] = A[i];
        rep(i, 0, N / 2) B[i * 2] = A[i + N / 2];
        ans = get();
    } else {
        rep(i, 0, N / 2) B[i * 2 + 1] = A[i];
        B[N-1] = A[N/2];
        rep(i, 0, N / 2) B[i * 2] = A[i + N / 2 + 1];
        chmax(ans, get());
 
        B[0] = A[N / 2];
        rep(i, 0, N / 2) B[i * 2 + 2] = A[i];
        rep(i, 0, N / 2) B[i * 2 + 1] = A[i + N / 2 + 1];
        chmax(ans, get());
    }
    
    cout << ans << endl;
}