#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> b(n - 1);
	for(int i = 0; i < n - 1; i++) {
		cin >> b[i];
	}
	if(n == 2) {
		cout << b[0] * 2 << endl;
		return 0;
	}
	vector<int> c(n);
	c[0] = b[0];
	c[n - 1] = b[n - 2];
	for(int i = 1; i < n - 1; i++) {
		c[i] = min(b[i], b[i - 1]);
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		ans += c[i];
	}
	cout << ans << endl;
}