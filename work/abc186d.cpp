#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	long long hikuSum = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 1; i < n; i++) {
		hikuSum += a[i];
	}
	long long ans = 0;
	for(int i = 0; i < n - 1; i++) {
		ans += abs(a[i] * (n - i - 1) - hikuSum);
		hikuSum -= a[i + 1];
	}
	cout << ans << endl;
}