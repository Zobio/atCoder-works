#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	int K;
	cin >> K;
	vector<bool> vis(K, false);
	deque<pair<int, int>> dq;
	dq.push_back(make_pair(1, 1));
	while (!dq.empty())
	{
		auto p = dq.front();
		dq.pop_front();
		int x = p.first;
		int d = p.second;
		cout << x << " " << d << endl;
		if (vis[x])
			continue;
		vis[x] = true;
		if (x == 0)
		{
			cout << d << endl;
			return 0;
		}
		dq.push_back(make_pair((x + 1) % K, d + 1)); //Kの倍数になるのを探している!!(1こ下も)
		dq.push_front(make_pair((10 * x) % K, d));
	}
	return 0;
}