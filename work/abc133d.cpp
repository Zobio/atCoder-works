#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> ans(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> aCopy = a;
	for(int i = 0; i <= a[0]; i++) {
		vector<int> aCopy = a;
		aCopy[0] -= i;
		aCopy[n - 1] -= i;
		ans[0] = i;
		for(int j = 1; j < n; j++) {
			int tmp = min(aCopy[j - 1], aCopy[j]);
			aCopy[j - 1] -= tmp;
			aCopy[j] -= tmp;
			ans[j] = tmp;
		}
		if(aCopy[0] == aCopy[n - 1]) {
			break;
		}
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] * 2 << " ";
	}
	cout << endl;
}