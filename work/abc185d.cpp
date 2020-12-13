#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if(n == m) {
		cout << 0 << endl;
		return 0;
	}
	else if(m == 0) {
		cout << 1 << endl;
		return 0;
	}
	vector<bool> blue(n, false);
	vector<int> a(m);
	for(int i = 0; i < m; i++) {
		cin >> a[i];
		a[i]--;
		blue[a[i]] = true;
	}
	sort(a.begin(), a.end());
	int mi = 2000000000;
	int cnt = 0;
	vector<int> white;
	for(int i = 0; i < n; i++) {
		if(!blue[i]) {
			cnt++;
		}else{
			if(cnt > 0) {
				white.push_back(cnt);
			}
			if(cnt < mi && cnt > 0) {
				mi = cnt;
			}
			cnt = 0;
		}
	}
	if(cnt > 0)
		white.push_back(cnt);
	long long ans = 0;
	for(int i = 0; i < white.size(); i++) {
		if(white[i] % mi == 0) {
			ans += white[i] / mi;
		}else{
			ans += white[i] / mi + 1;
		}
	}
	cout << ans << endl;
}