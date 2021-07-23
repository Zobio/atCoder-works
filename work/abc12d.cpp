#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dist(n, vector<int>(n, MOD));
	for(int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		a--; b--;
		dist[a][b] = t;
		dist[b][a] = t; //無向グラフ
	}

	for(int i = 0; i < n; i++) dist[i][i] = 0;

	for(int k = 0; k < n; k++) { //中継点
		for(int i = 0; i < n; i++) { //始点
			for(int j = 0; j < n; j++) { //終点
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = MOD;
	for(int i = 0; i < n; i++) {
		int now = 0;
		for(int j = 0; j < n; j++) {
			now = max(now, dist[i][j]);
		}
		ans = min(ans, now);
	}
	cout << ans << endl;
}