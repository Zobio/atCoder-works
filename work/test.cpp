#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define MOD 1000000007LL
#define INF 1LL << 60

ll n, m;
ll MAX_M = 15;
vector<vector<bool>> color;
vector<vector<ll>> dp(2, vector<ll>(1ll << MAX_M));

void solve() {
    vector<ll> crt = dp[0], nxt = dp[1];
    crt[0] = 1;
    rrep(i, n) rrep(j, m) {
        rep(used, 1 << m) {
            if((used >> j) & 1 || color[i][j]) nxt[used] = crt[used & ~(1 << j)]; //置く必要がない
            else {
                //2通りの向きを試す
                ll res = 0;
                //横向き
                if(j + 1 < m) if(!(used >> (j + 1) & 1) && !color[i][j + 1])
                    res += crt[used | 1 << (j + 1)];
                //縦向き
                if(i + 1 < n) if(!color[i + 1][j])
                    res += crt[used | 1 << j];
                nxt[used] = res % MOD;
            }
        }
        swap(crt, nxt);
    }
    cout << crt[0] << endl;
}

int main() {
    cin >> n >> m;
    color.resize(n, vector<bool>(m));
    rep(i, n) {
        string s; cin >> s;
        rep(j, m) color[i][j] = s[j] == 'x' ? true : false;
    }
    solve();
}