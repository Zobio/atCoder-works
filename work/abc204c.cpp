#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

vector<vector<int>> mov;
vector<bool> tmp;

void dfs(int v) {
	if(tmp[v])return;
	tmp[v]=true;
	for(auto i : mov[v]) {
		dfs(i);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	mov.resize(n);
	tmp.resize(n);
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		mov[a - 1].push_back(b - 1);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)	tmp[j] = false;
		dfs(i);
		for (int j = 0; j < n; j++)	if(tmp[j]) ans++;
	}
	cout << ans << endl;
}