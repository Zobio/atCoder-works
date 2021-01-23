#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> ans(n);
	int cnt = 0;
	int fix = 0;
	for(int i = n - 1; i >= 0; i--) {
		fix = i + 1;
		for(int j = fix * 2; j < n; j += fix) {
			cnt += ans[j];
		}
		cnt %= 2;
		if(cnt != a[i]) {
			ans[i] = 1;
		}else{
			ans[i] = 0;
		}
	}
	cnt = 0;
	for(int i = 0; i < n; i++) {
		if(ans[i])cnt++;
	}
	cout << cnt << endl;
	for(int i = 0; i < n; i++) {
		if(ans[i])
		cout << i + 1 << endl;
	}
}