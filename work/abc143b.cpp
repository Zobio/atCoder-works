#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> d(n);
	for(int i = 0; i < n; i++) {
		cin >> d[i];
	}
	long long sum = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			sum += d[i] * d[j];
		}
	}
	cout << sum << endl;
}