#include <bits/stdc++.h>
using namespace std;

int main() {
	double n;
	cin >> n;
	double ans = 1.0;
	if(n == 1) {
		ans = 1;
	}
	else if((int)n % 2 == 0) {
		ans = 0.5;
	}
	else{
		ans = ((int)(n / 2) + 1) / n;
	}
	cout << fixed << setprecision(10) << ans << endl;
}