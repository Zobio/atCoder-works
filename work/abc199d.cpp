#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

const int maxn = 22;
int n, m;
vector<int> a(m);
vector<int> b(m);
vector<vector<int>> edge(maxn);
int vis[maxn];

ll dfs(int x) {
	if(x == n + 1)return 1;
	if(edge[x].empty())return dfs(x+1)*3;
	ll ans = 0;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
}