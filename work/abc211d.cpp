#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007LL
#define INF 1LL << 60

int n, m;
vector<vector<ll>> g;
vector<ll> ans;
vector<ll> dist;

void bfs() {
	queue<int> q;
	q.push(0);
	ans[0] = 1;
	while(!q.empty()) {
		int now = q.front(); q.pop();
		for(auto a : g[now]) {
			if(dist[a] == -1) {
				dist[a] = dist[now] + 1;
				q.push(a);
			}
			if(dist[a] == dist[now] + 1) {
				ans[a] = (ans[a] + ans[now]) % MOD;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	g.resize(n);
	ans.resize(n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	rep(i, n)sort(g[i].begin(), g[i].end());
	dist.resize(n, -1); // 全頂点を「未訪問」に初期化
	bfs();
	cout << ans[n - 1] << endl;
}