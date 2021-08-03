#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> x(m);
	rep(i, m) cin >> x[i];
	sort(x.begin(), x.end());
	vector<int> dist;
	for(int i = 1; i < m; i++) {
		dist.push_back(x[i] - x[i - 1]);
	}
	sort(dist.begin(), dist.end());
	ll ans = 0;
	for(int i = 0; i < m - n; i++) {
		ans += dist[i];
	}
	cout << ans << endl;
}