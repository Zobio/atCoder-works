#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> p(m), y(m);
	for(int i = 0; i < m; i++) {
		cin >> p[i] >> y[i];
		p[i]--;
	}
	vector<vector<int>> vals(n);
	for(int i = 0; i < m; i++) {
		vals[p[i]].push_back(y[i]);
	}
	for(int i = 0; i < n; i++) {
		sort(vals[i].begin(), vals[i].end());
	}
	int pl;
	for(int j = 0; j < m; j++) {
		for(int i = 0; i < 6 - to_string(p[j] + 1).length(); i++) {
			cout << "0";
		}
		cout << p[j] + 1;
		pl = lower_bound(vals[p[j]].begin(), vals[p[j]].end(), y[j]) - vals[p[j]].begin();
		pl++;
		for(int i = 0; i < 6 - to_string(pl).length(); i++) {
			cout << "0";
		}
		cout << pl << endl;
	}
}