#include <bits/stdc++.h>
using namespace std;

int main() {
    const long long MOD = 1e9 + 7;
    long long n; cin >> n;
    cout << (n * (n + 1) * (2 * n + 1) / 6) % MOD << endl;
}