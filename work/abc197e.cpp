#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	sort(v.begin(), v.end());
	pair<int, int> x, y;
	x = {0, 0};
	y = {0, 0};
	for(int i = 1; i <= n; i++) if(v.size()) {
		int dx = min(x.first + abs(x.second - v[i].back()), y.first + abs(y.second - v[i].back()));
		int dy = min(x.first + abs(x.second - v[i].front()), y.first + abs(y.second - v[i].front()));
		x = {dx + v[i].back() - v[i].front(), v[i].front()};
		y = {dy + v[i].back() - v[i].front(), v[i].back()};
	}
	cout << min(x.first + abs(x.second), y.first + abs(y.second)) << endl;
}