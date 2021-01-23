#include <bits/stdc++.h>
using namespace std;

int main() {
	double n, x;
	cin >> n >> x;
	vector<double> v(n);
	vector<double> p(n);
	x *= 100;
	for(int i = 0; i < n; i++) {
		cin >> v[i] >> p[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		x -= v[i] * p[i];
		ans++;
		if(x < 0)break;
	}
	if(x < 0)
	cout << ans << endl;
	else
	cout << -1 << endl;
}