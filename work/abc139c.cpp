#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(n == 1) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> h(n);
	int cnt = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for(int i = 1; i < n; i++) {
		if(h[i - 1] < h[i]) {
			if(cnt > ans) {
				ans = cnt;
			}
			cnt = 0;
		}else{
			cnt++;
		}
	}
	if (cnt > ans) {
		ans = cnt;
	}
	cout << ans << endl;
}