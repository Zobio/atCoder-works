#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m, c;
	cin >> n >> m >> c;
	vector<int> b(m);
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int now = 0, cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			now += b[j] * a[i][j];
		}
		now += c;
		if(now > 0) cnt++;
		now = 0;
	}
	cout << cnt << endl;
}