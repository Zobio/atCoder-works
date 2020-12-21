#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	double ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		ans += 1.0 / a[i];
	}
	cout << fixed << setprecision(10) << 1 / ans << endl;
}