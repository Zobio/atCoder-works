#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ll n;
	cin >> n;
	if(n == 1) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1;
	ll minus = 2;
	ll plus = 1;
	for(int i = 0; i < n; i++) {
		ans = (ans * 10) % MOD; //全列挙
		minus = (minus * 9) % MOD;
		plus = (plus * 8) % MOD;
	}
	cout << ((ans - minus + plus) + MOD) % MOD << endl;
}