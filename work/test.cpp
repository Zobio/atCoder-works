#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

ll mpow(ll a, ll b) {
	long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
	ll a, b;
	cin >> a; cin >> b;
	cout << mpow(a, b) << endl;
}