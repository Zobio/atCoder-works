#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, x;
	cin >> a >> b >> x;
	double ans = 0;
	if(a * b / 2 > x) {
		ans = 90.0 - atan(2 * x / b / b);
	}
	cout << fixed << setprecision(10) << ans << endl;
}