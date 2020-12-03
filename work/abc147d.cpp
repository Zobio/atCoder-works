#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> bitCount(60);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 60; j++) {
			if((a[i] >> j) % 2 == 1) {
				bitCount[j]++;
			}
		}
	}
	long long ans = 0;
	long long base = 1;
	long long mod = 1000000007;
	for (int i = 0; i < 60; i++) {
		ans += (base % mod) * bitCount[i] * (n - bitCount[i]) % mod;
		base *= 2;
	}
	cout << (ans % mod) << endl;
}