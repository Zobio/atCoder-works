#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m;
	cin >> n >> m;
	priority_queue<int, vector<int>, greater<int>> a;
	for(int i = 0; i < n; i++) {
		int q;
		cin >> q;
		a.push(q);
	}
	priority_queue<pair<int, int>> bc;
	for(int i = 0; i < m; i++) {
		int ta, tb;
		cin >> ta >> tb;
		bc.push(make_pair(tb, ta));
	}
	while(!bc.empty()) {
		auto bTop = bc.top();
		for(int i = 0; i < bTop.second; i++) {
			if(a.top() >= bTop.first) break;
			a.pop(); a.push(bTop.first);
		}
		bc.pop();
	}
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans += a.top(); a.pop();
	}
	cout << ans << endl;
} 