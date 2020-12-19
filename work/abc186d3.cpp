#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<long long> diff(n - 1);
	for(int i = 0; i < n - 1; i++) {
		diff[i] = a[i] - a[i + 1];
	}
	long long ans = 0;
	long long now = 0;
	for(int i = 0; i < n; i++) {
		now = 0;
		for(int j = i; j < n - 1; j++) {
			now += diff[j];
			ans += abs(now);
		}
	}
	cout << ans << endl;
}