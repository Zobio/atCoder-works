#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define reps(i, n) for (long long i = 1; i <= n; i++)

int main() {
    ll n, t; cin >> n >> t;
    ll u = (n + 1) * (n + 1) * (n + 1);
    ll cnt = 0;
    reps(i, min(n, t)) for(ll j = 1; i + j < t && j <= n; j++) {
        ll p = t - (i + j);
        if(p > n) continue;
        cnt += ((i == 1) + 1) * ((j == 1) + 1) * ((p == 1) + 1);
    }
    ll gc = __gcd(cnt, u);
    cnt /= gc; u /= gc;
    cout << cnt << "/" << u << endl;
}