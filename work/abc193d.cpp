#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int k;
	cin >> k;
	string s, t;
	cin >> s >> t;
	vector<int> sum(10, k);
	vector<int> sSum(10, k);
	vector<int> tSum(10, k);
	ll all = 9 * k - 8;
	for(int i = 0; i < 4; i++) {
		sum[s[i] - '0']--;
		sSum[s[i] - '0']++;
	}
	for(int i = 0; i < 4; i++) {
		sum[t[i] - '0']--;
		tSum[t[i] - '0']++;
	}
	double ans = 0;
	ll a = 0, b = 0;
	for(int i = 1; i < 10; i++) {
		if(sum[i] == 0) continue;
		for(int j = 1; j < 10; j++) {
			if(sum[j] == 0) continue;
			sSum[i]++; tSum[j]++;
			for(int q = 1; q < 10; q++) {
				a += q * pow(10, sSum[q]);
				b += q * pow(10, tSum[q]);
			}
			cout << "a: " << a << " b: " << b << endl;
			if(a > b) ans += (double)(sum[i] / all * sum[j] / (all - 1));
			a = 0; b = 0;
			sSum[i]--; tSum[j]--;
		}
	}
	cout << ans << endl;
}