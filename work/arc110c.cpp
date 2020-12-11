#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	vector<bool> yet(n - 1, true);
	vector<int> ans(n - 1);
	int ansNum = 0;
	for(int i = 0; i < n; i++) {
		cin >> p[i];
	}
	int point = 0, tmp = 0;
	for(int i = 1; i <= n; i++) {
		if(i == p[i - 1])
		continue;
		for(int j = 0; j < n; j++) {
			if(p[j] == i) {
				point = j;
			}
		}
		while(i - 1 != point) {
			if(!yet[point - 1]) {
				cout << -1 << endl;
				return 0;
			}
			swap(p[point], p[point - 1]);
			yet[point - 1] = false;
			ans[ansNum] = point;
			ansNum++;
			point--;
		}
	}
	for(int i = 0; i < n - 1; i++) {
		cout << ans[i] << endl;
	}
}