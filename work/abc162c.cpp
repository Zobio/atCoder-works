#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

long long gcd(long long a, long long b) {
	// a<bのときa % b == aなので結局gcd(b, a)に帰結する。
	if (a % b == 0) {
		return b;
	}else{
		return gcd(b, a % b);
	}
}

int main() {
	ll k;
	cin >> k;
	ll ans = 0;
	for(int a = 1; a <= k; a++) {
		for(int b = 1; b <= k; b++) {
			for(int c = 1; c <= k; c++) {
				ans += gcd(a, gcd(b, c));
			}
		}
	}
	cout << ans << endl;
}