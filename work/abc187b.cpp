#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<double> x(n);
	vector<double> y(n);
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	int cnt = 0;
	double k;
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			k = (y[i] - y[j]) / (x[i] - x[j]);
			if (k >= -1 && k <= 1) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}