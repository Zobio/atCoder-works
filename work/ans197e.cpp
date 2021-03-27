#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi acos(-1.0)
const int inf = 1e9;
signed main() {
	
	int n;
	cin >> n;
	vector<int> v[n + 1];
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end());
	pair<int, int> X, Y;
	X = {0, 0};
	Y = {0, 0};
	for (int j = 1; j <= n; j++) if (v[j].size()){
		int dx = min(X.first + abs(X.second - v[j].back()), Y.first + abs(Y.second - v[j].back()));
		int dy = min(X.first + abs(X.second - v[j].front()), Y.first + abs(Y.second - v[j].front()));
		X = {dx + v[j].back() - v[j].front(), v[j].front()};
		Y = {dy + v[j].back() - v[j].front(), v[j].back()};
		cout << X.first << " " << X.second << "  " << Y.first << " " << Y.second << endl;
	}
	cout << min(X.first + abs(X.second), Y.first + abs(Y.second)) << endl;

}
