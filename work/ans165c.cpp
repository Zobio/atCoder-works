#include <iostream>
using namespace std;
int N, M, Q;
int a[50], b[50], c[50], d[50];
int ans;
int A[10];
void dfs(int id, int pre)
{
	cout << id << " " << pre << endl;
	/*if(id == N)*/{
	for(int i = 0; i < N; i++) {
		cout << A[i] << " ";
	}cout << endl;}
	if (id == N)
	{
		int now = 0;
		for (int i = 0; i < Q; i++)
			if (A[b[i] - 1] - A[a[i] - 1] == c[i])
				now += d[i];
		if (ans < now)
			ans = now;
	}
	else
	{
		for (int i = pre; i <= M; i++)
		{
			A[id] = i;
			dfs(id + 1, i);
		}
	}
}
int main()
{
	cin >> N >> M >> Q;
	for (int i = 0; i < Q; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	dfs(0, 1);
	cout << ans << endl;
}
