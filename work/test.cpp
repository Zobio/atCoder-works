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
int v[3] = { 3,5,7 };
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    int ans = 0;
 
    rep(dgt, 3, 10) {
        int ma = 1;
        rep(i, 0, dgt) ma *= 3;
 
        rep(msk, 0, ma) {
            int x = 0;
            int m = msk;
            int cn[3] = { 0, 0, 0 };
            rep(i, 0, dgt) {
                int d = m % 3;
                x = x * 10 + v[d];
                cn[d]++;
                m /= 3;
            }
			cout << msk << endl;
            if (x <= N and 0 < cn[0] and 0 < cn[1] and 0 < cn[2]) ans++;
        }
    }
 
    cout << ans << endl;
}