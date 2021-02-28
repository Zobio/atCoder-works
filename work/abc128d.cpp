#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int act = min(n, k);
	ll ans = 0;
	for(int i = 0; i <= act; i++) {
		for(int j = 0; i + j <= act; j++) {
			vector<ll> ju;
			ll sum = 0;
			for(int a = 0; a < i; a++) {
				ju.push_back(v[a]);
				sum += v[a];
			}
			for(int b = 0; b < j; b++) {
				ju.push_back(v[n - 1 - b]);
				sum += v[n - 1 - b];
			}
			sort(ju.begin(), ju.end());
			for(int c = 0; c < min(k - i - j, (int)ju.size()); c++) {
				if(ju[c] < 0) sum -= ju[c];
			}
			if(sum > ans) ans = sum;
			sum = 0;
		}
	}
	cout << ans << endl;
}