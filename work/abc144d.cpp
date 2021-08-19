#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, x;
	cin >> a >> b >> x;
	double ans = 0;
	if(a * b / 2 > x) {
		cout << fixed << setprecision(10) << atan(a * b * b / (2 * x)) << endl;
	}else{
		cout << fixed << setprecision(10) << atan((2 * b  - (x / (a / a))) / a) << endl;
	}
}