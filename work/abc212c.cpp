#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> li;
	rep(i, n) {
		int a;
		cin >> a;
		li.push_back(make_pair(a, 0));
	}
	rep(i, m) {
		int a;
		cin >> a;
		li.push_back(make_pair(a, 1));
	}
	sort(li.begin(), li.end());
	int ans = 1000000009;
	for(int i = 1; i < n + m; i++) {
		if(li[i].second == li[i - 1].second) continue;
		ans = min(ans, li[i].first - li[i - 1].first);
	}
	cout << ans << endl;
}