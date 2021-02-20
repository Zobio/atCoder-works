#include <bits/stdc++.h>
using namespace std;

bool isOkay(long long sum) {
	for(int i = 1; i <= sqrt(sum); i++) {
		if(sum % (i * i) == 0 && i != 1) {
			while(sum % (i * i) == 0 && sum != 1) {
				sum /= i * i;
			}
		}
		if(sum == 1) return true;
	}
	return false;
}

int main() {
	int n, d;
	cin >> n >> d;
	long long sum = 0;
	long long ans = 0;
	vector<vector<double>> x(n, vector<double>(d));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < d; j++) {
			cin >> x[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			for(int k = 0; k < d; k++) {
				sum += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
			}
			if(isOkay(sum))ans++;
			sum = 0;
		}
	}
	cout << ans << endl;
}