#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> dr;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		dr.push_back(make_pair(a, b));
	}
	sort(dr.begin(), dr.end());
	int now = 0; ll ans = 0;
	while(m > 0) {
		int use = min(m, dr[now].second);
		ans += (ll)dr[now].first * use;
		m -= use;
		now++;
	}
	cout << ans << endl;
}