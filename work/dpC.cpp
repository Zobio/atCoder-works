#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	vector<int> dpA(n);
	vector<int> dpB(n);
	vector<int> dpC(n);
	dpA[0] = a[0], dpB[0] = b[0], dpC[0] = c[0];
	for(int i = 1; i < n; i++) {
		dpA[i] = a[i] + max(dpB[i - 1], dpC[i - 1]);
		dpB[i] = b[i] + max(dpC[i - 1], dpA[i - 1]);
		dpC[i] = c[i] + max(dpA[i - 1], dpB[i - 1]);
	}
	cout << max(max(dpA[n - 1], dpB[n - 1]), max(dpB[n - 1], dpC[n - 1])) << endl;
}