#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> cond(m);
	for(int i = 0; i < m; i++) {
		cin >> cond[i].first >> cond[i].second;
	}
	int k;
	cin >> k;
	vector<pair<int, int>> choice(k);
	for(int i = 0; i < k; i++) {
		cin >> choice[i].first >> choice[i].second;
	}
	int ans = 0;
	for(int bit = 0; bit < 1 << k; bit++) {
		vector<bool> ball(n);
		for(int i = 0; i < k; i++) {
			const auto [C, D] = choice[i];
			ball[bit & 1 << i ? C : D] = 1;
		}
		int cnt = 0;
		for(int i = 0; i < m; i++) {
			if(ball[cond[i].first] && ball[cond[i].second]) {
				cnt++;
			}
		}
		if(cnt > ans) ans = cnt;
	}
	cout << ans << endl;
}