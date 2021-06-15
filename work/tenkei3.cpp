#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

vector<int> dist;
int ans = 0;
int n;
const int INF = (1 << 29);
vector<vector<int>> root;

void getDist(int start) {
	for (int i = 0; i < n; i++)	dist[i] = INF;
	queue<int> Q;
	Q.push(start);
	dist[start] = 0;
	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		for (int to : root[pos]) {
			if (dist[to] == INF) {
				dist[to] = dist[pos] + 1;
				Q.push(to);
			}
		}
	}
}

int main() {
	cin >> n;
	dist.resize(n);
	root.resize(n);
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		root[a - 1].push_back(b - 1);
	}
	getDist(0);
	int maxn1 = -1, maxid1 = -1;
	for(int i = 0; i < n; i++) {
		cout << maxn1 << endl;
		cout << maxid1 << endl;
		if(dist[i] > maxn1) {
			maxn1 = dist[i];
			maxid1 = i;
		}
	}
	getDist(maxid1);
	for(auto a : dist) cout << "   " << a << endl;
	int maxn2 = -1, maxid2 = -1;
	for (int i = 0; i < n; i++) {
		cout << "dist: " << dist[i] << endl;
		if(dist[i] != INF)
		maxn2 = max(maxn2, dist[i]);
		cout << maxn2 << endl;
	}
	cout << maxn2 << endl;
}