#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<double> x(n);
	vector<double> y(n);
	vector<double> idx(n);
	for(int i = 0; i < n; i++){
		idx[i] = i;
	}
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	double ans = 0;
	int cnt = 1;
	do {
		for(int i = 0; i < n - 1; i++) {
		ans += sqrt(pow((x[idx[i]] - x[idx[i + 1]]), 2) + pow((y[idx[i]] - y[idx[i + 1]]), 2));
		}
	} while(next_permutation(idx.begin(), idx.end()));
	for(int i = 1; i <= n; i++) {
		cnt *= i;
	}
	ans /= cnt;
	cout << setprecision(15) << ans << endl;
}