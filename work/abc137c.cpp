#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a, b;
	vector<vector<int>> bi(m + 1);
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a <= m)
		bi[a].push_back(b);
	}
	priority_queue<int> q;
	long long ans = 0;
	for(int i = 1; i <= m; i++) {
		for(int j = 0; j < bi[i].size(); j++) {
			q.push(bi[i][j]);
		}
		if(!q.empty()){
		ans += q.top(); q.pop();
		}
	}
	cout << ans << endl;
}