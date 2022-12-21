#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
int MOD = 10;
struct ModInt {
    unsigned x; ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u);
    }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : MOD - x; return t; }
};
typedef ModInt mint;
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/











int N;
vector<int> E[101010];
//---------------------------------------------------------------------------------------------------
mint dp[101010];
void dfs1(int cu, int pa = -1) {
    dp[cu] = 1;
    fore(to, E[cu]) if (to != pa) {
        dfs1(to, cu);
        dp[cu] *= dp[to] + 1;
    }
}
//---------------------------------------------------------------------------------------------------
mint ans[101010];
void dfs2(int cu, int pa = -1) {
    ans[cu] = 1;
    fore(to, E[cu]) ans[cu] *= dp[to] + 1;

    int n = E[cu].size();
    vector<mint> lft(n), rht(n);
    rep(i, 0, n) lft[i] = rht[i] = dp[E[cu][i]] + 1; //今回のleftとright
    rep(i, 1, n) lft[i] *= lft[i - 1];
    rrep(i, n - 2, 0) rht[i] *= rht[i + 1];

    rep(i, 0, n) if (E[cu][i] != pa) {
        dp[cu] = 1;
        if (i) dp[cu] *= lft[i - 1];
        if (i + 1 < n) dp[cu] *= rht[i + 1];
        dfs2(E[cu][i], cu);
    }
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> MOD;
    rep(i, 0, N-1) {
        int x, y; cin >> x >> y;
        x--; y--;
        E[x].push_back(y);
        E[y].push_back(x);
    }

    dfs1(0);
    dfs2(0);

    rep(i, 0, N) printf("%d\n", ans[i].get());
}
