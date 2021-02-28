#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> li(m, vector<bool>(n, false));
	for(int i = 0; i < m; i++) {
		int k;
		cin >> k;
		for(int j = 0; j < k; j++) {
			int t;
			cin >> t;
			t--;
			li[i][t] = true;
		}
	}
	vector<int> odd(m);
	ll ans = 0;
	int ccnt = 0;
	for(int i = 0; i < m; i++) {
		cin >> odd[i];
	}
	for(int i = 0; i < (1 << n); i++) {
		vector<int> cnt(m);
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) {
				for(int k = 0; k < m; k++) {
					if(li[k][j]) cnt[k]++;
				}
			}
		}
		for(int j = 0; j < m; j++) {
			if(cnt[j] % 2 == odd[j]) ccnt++;
			else break;
		}
		if(ccnt == m) ans++;
		ccnt = 0;
	}
	cout << ans << endl;
}