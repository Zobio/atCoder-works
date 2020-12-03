#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<long long> bitCount0(60);
	vector<long long> bitCount1(60);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 60; j++) {
			if((a[i] >> j) & 1) {
				bitCount1[j]++;
			}else{
				bitCount0[j]++;
			}
		}
	}
	long long ans = 0;
	long long base = 1;
	long long mod = 1000000007;
	long long bit = 0;
	for (int i = 0; i < 60; i++) {
		base = (1ll << i) % mod;
		bit = (bitCount0[i] * bitCount1[i]) % mod;
		ans = (ans + (base * bit) % mod) % mod;
	}
	cout << (ans % mod) << endl;
}