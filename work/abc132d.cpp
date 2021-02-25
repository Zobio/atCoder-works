#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

unsigned long long nCr(unsigned long long a, unsigned long long b) {
	if(b == 0 || a == b) return 1;
	if(a / 2 < b) b = a - b;
	vector<bool> r(b + 1, false);
	unsigned long long aCopy = a;
	unsigned long long bCopy = b;
	for(unsigned long long i = aCopy - 1; i > aCopy - bCopy; i--) {
		a %= MOD;
		for(unsigned long long j = 2; j <= b; j++) {
			if(!r[j] && a % j == 0) {
				a /= j;
				r[j] = true;
			}
		}
		a *= i;
	}
	return a % MOD;
}

int main() {
	unsigned long long n, k;
	cin >> n >> k;
	unsigned long long ans = 0;
	for(unsigned long long i = 1; i <= k; i++) {
		if (n - k < i - 1) {
			cout << 0 << endl;
			continue;
		}
		ans = nCr(n - k + 1, i) % MOD * nCr(k - 1, i - 1) % MOD;
		ans %= MOD;
		cout << /*nCr(n - k + 1, i) << " " << nCr(k - 1, i - 1) << " " << */ans << endl;
	}
}