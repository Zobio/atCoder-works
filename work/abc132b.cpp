#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int key;
	cin >> n;
	vector<int> p(n);
	vector<int> test;
	for(int i = 0; i < n; i++) {
		cin >> p[i];
	}
	int ans = 0;
	for(int i = 1; i < n - 1; i++) {
		key = p[i];
		for(int j = i - 1; j <= i + 1; j++) {
			test.push_back(p[j]);
		}
		sort(test.begin(), test.end());
		if(key == test[1]) {
			ans++;
		}
		test.clear();
	}
	cout << ans << endl;
}