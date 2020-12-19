#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n - 1);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> c[i];
	}
	long long ans = 0;
	ans += b[a[0]];
	for(int i = 1; i < n; i++) {
		ans += b[a[i]];
		if(a[i] - 1 == a[i - 1]) {
			ans += c[a[i] - 1];
		}
	}
	cout << ans << endl;
}