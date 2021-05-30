#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main()
{
	int k, n;
	cin >> n >> k;
	vector<vector<ll>> a(n, vector<ll>(n));
	vector<pair<ll, pair<int, int>>> pl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			pl.push_back(make_pair(a[i][j], make_pair(i, j)));
		}
	}
	sort(pl.begin(), pl.end());
	//それぞれでその数が中央値になれるかどうか判定していく
	int po = (k * k) / 2;
	//cout << "po: " << po << endl;
	for (int i = (k * k) / 2; i < n * n; i++)
	{
		//cout << pl[i].first << endl;
		priority_queue<ll> pq;
		for (int aa = 0; aa < k; aa++)
		{
			for (int bb = 0; bb < k; bb++)
			{
				for (int j = pl[i].second.first - aa; j < pl[i].second.first + k - aa && j < n; j++)
				{
					for (int l = pl[i].second.second - bb; l < pl[i].second.second + k - bb && l < n; l++)
					{
						//cout << a[j][l] << endl;
						pq.push(a[j][l]);
					}
				} //cout << endl;
				for (int j = 0; j < po; j++)
				{
					pq.pop();
					if (pq.empty())
						break;
				}
				if (pq.top() == pl[i].first && pq.size() == k * k - po)
				{
					cout << pl[i].first << endl;
					return 0;
				}
				while (!pq.empty())
					pq.pop();
			}
		}
	}
}