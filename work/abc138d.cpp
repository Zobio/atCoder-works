#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

vector<ll> ans;
vector<vector<int>> tree;

void dfs(int now, int par) {
	if(par != -1) ans[now] += ans[par];
	for(auto a : tree[now]) {
		if(a != par) dfs(a, now);
	}
}

int main() {
	int n, q;
	cin >> n >> q;
	ans.resize(n);
	tree.resize(n);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	rep(i, q) {
		int a; ll b;
		cin >> a >> b;
		ans[--a] += b;
	}
	dfs(0, -1);
	rep(i, n) cout << (i ? " " : "") << ans[i];
	cout << endl;
}