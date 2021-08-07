#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(i) cout << i << endl

ll pow(ll a, ll b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll mpow(ll a, ll b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}