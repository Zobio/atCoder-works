#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(a) cout << a << endl

vector<vector<int>> g;
vector<int> ans;

void dfs(int now, int pre) {
	ans.push_back(now);
	for(int i = 0; i < g[now].size(); i++) {
		if(g[now][i] != pre) {
			dfs(g[now][i], now);
			ans.push_back(now);
		}
	}
}

int main() {
	int n;
	cin >> n;
	g.resize(n + 1);
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());
	dfs(1, -1);
	for(int i = 0; i < ans.size(); i++) {
		cout << (i ? " " : "") << ans[i];
	}
	cout << endl;
}