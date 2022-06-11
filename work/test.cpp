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

int N; ll X;
//---------------------------------------------------------------------------------------------------
ll patty[51], tot[51];
ll f(int level, ll x) {
	cout << level << " " << x << endl;
    if (level == 0) return 1;
 
    if (x < 1) return 0;
    x--;
 
    if (x < tot[level - 1]) return f(level - 1, x);
    x -= tot[level - 1];
 
    if (x < 1) return patty[level - 1] + 1;
    x--;
 
    if (x < tot[level - 1]) return patty[level - 1] + 1 + f(level - 1, x);
    x -= tot[level - 1];
 
    return patty[level - 1] * 2 + 1;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> X;
    X--;
 
    tot[0] = 1;
    rep(L, 1, N + 1) tot[L] = tot[L - 1] * 2 + 3;
    patty[0] = 1;
    rep(L, 1, N + 1) patty[L] = patty[L - 1] * 2 + 1;
 
    cout << f(N, X) << endl;
}