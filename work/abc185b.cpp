#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, t, a, b;
	cin >> n >> m >> t;
	int max = n;
	int now = 0;
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		n -= a - now;
		if(n <= 0) {
			cout << "No" << endl;
			return 0;
		}
		n += b - a;
		if(n > max) n = max;
		now = b;
	}
	n -= t - b;
	cout << (n <= 0 ? "No" : "Yes") << endl;
}