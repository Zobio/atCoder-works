#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	priority_queue<int> a;
	int tmp;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		a.push(tmp);
	}
	for(int i = 0; i < m; i++) {
		a.push(a.top() / 2);
		a.pop();
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		ans += a.top();
		a.pop();
	}
	cout << ans << endl;
}