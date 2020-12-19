#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end(), greater<int>());
	for(int i = 0; i < m; i++) {
		a[0] /= 2;
		sort(a.begin(), a.end(), greater<int>());
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		ans += a[i];
	}
	cout << ans << endl;
}