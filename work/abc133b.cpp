#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	vector<vector<int>> x(n, vector<int>(d));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < d; j++) {
			cin >> x[i][j];
		}
	}
	long long ans = 0;
	double sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			sum += x[i][j]
		}
	}
}