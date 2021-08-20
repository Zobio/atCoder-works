#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 1LL << 60

int main() {
	ll n, m;
	cin >> n >> m;
	vector<vector<int>> wo(m + 1);
	rep(i, n) {
		int a, b; cin >> a >> b;
		if(a <= m) wo[a].push_back(b);
	}
	priority_queue<int> pq;
	ll ans = 0;
	for(int i = 0; i <= m; i++) {
		for(auto j : wo[i]) pq.push(j);
		if(!pq.empty()) ans += pq.top(), pq.pop();
	}
	cout << ans << endl;
}