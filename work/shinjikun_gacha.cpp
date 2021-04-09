#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

double nCr(int n, int r) {
	if (n == 0) { return 0; }
	if (r == 0) { return 1; }
	if (r == 1) { return n; }
	if (n == r) { return 1; }
	if (r > n / 2) { r = n / 2; }
	double result = 1;
	int sn = n - r + 1;
	for (double i = 1; i <= r; i++) {
		result *= sn / i;
		sn++;
	}
	return(result);
}

int main() {
	cout << "シンジ君の提供割合を1.2%だとして計算します" << endl;
	for(int i = 50; i <= 200; i += 50) {
		double ans = 0;
		for(int j = 13; j <= i; j++) {
			ans += pow(0.012, j) * pow(0.988, i - j) * nCr(i, j);
			cout << ans << endl;
		}
		cout << setprecision(10) << fixed <<  i << "連であたる確率: " << ans * 100 << "%" << endl;
	}
}