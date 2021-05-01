#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 22;
int n, m, x, y;
vector<int> edge[maxn];
long long ans, all = 1;
int vis[maxn];

ll dfs(int x)
{
	cout << x << " " << ans << endl;
	if (x == n + 1)
		return 1;
	if (edge[x].empty())
		return dfs(x + 1) * 3;
	ll ans = 0;
	for (int i = 1; i <= 3; i++)
	{
		bool flag = 0;
		for (int y : edge[x])
			if (vis[y] == i)
			{
				flag = 1;
				break;
			}
		if (flag)
			continue;
		vis[x] = i;
		ans += dfs(x + 1);
		vis[x] = 0;
	}
	return ans;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	cout << dfs(1) << endl;
	return 0;
}