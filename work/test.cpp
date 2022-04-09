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

int H, W, A[505][505];
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> H >> W;
    rep(y, 0, H) rep(x, 0, W) cin >> A[y][x];
 
    vector<tuple<int, int, int, int>> ans;
    rep(y, 0, H) rep(x, 0, W - 1) {
        if (A[y][x] % 2 == 1) {
            A[y][x]--;
            A[y][x + 1]++;
            ans.push_back(make_tuple(y, x, y, x + 1));
        }
    }
    rep(y, 0, H - 1) {
        if (A[y][W-1] % 2 == 1) {
            A[y][W - 1]--;
            A[y + 1][W - 1]++;
            ans.push_back(make_tuple(y, W - 1, y + 1, W - 1));
        }
    }
 
    int n = ans.size();
    printf("%d\n", n);
    fore(t, ans) {
        int a, b, c, d;
        tie(a, b, c, d) = t;
        printf("%d %d %d %d\n", a + 1, b + 1, c + 1, d + 1);
    }
}