#include <bits/stdc++.h>
using namespace std;

double nCr(double n, double r) {
	if (n == 0) 
		return 0;
	if (r == 0 || n == r)
		return 1;
	if (r == 1) 
		return n;
	double result = 1;
	int sn = n - r + 1;
	for (double i = 1; i <= r; i++) {
		result *= sn / i;
		sn++;
	}
	return(result);
}

int main() {
	double prob = 0.012;
	int expected_num = 13;
	for(int i = 50; i <= 1000; i += 50) {
		double ans = 0;
		for(int j = expected_num; j <= i; j++) {
			ans += pow(prob, j) * pow(1 - prob, i - j) * nCr((double)i, (double)j);
			//N回当たる確率 = 当たる確率 * 当たらない確率 * 組み合わせの数
		}
		cout << setprecision(10) << fixed <<  i << "連であたる確率: " << ans * 100 << "%" << endl;
	}
}