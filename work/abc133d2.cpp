#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int key = a[0];
	for(int i = 1; i < n - 1; i++) {
		key = a[i] - key;
	}
	vector<int> ans(n);
	ans[0] = (a[n - 1] - key) / 2;
	for(int i = 1; i < n; i++) {
		ans[i] = a[i - 1] - ans[i - 1];
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] * 2 << " ";
	}
	cout << endl;
}