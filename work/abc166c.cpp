#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	int n, m; cin >> n >> m;
	vector<ll> h(n); rep(i, n) cin >> h.at(i);
	vector<vector<int>> g(n);
	rep(i, m) {
		ll a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ll cnt = 0;
	rep(i, n) {
		bool flag = true;
		rep(j, g[i].size()) {
			if(h[g[i][j]] >= h[i]) flag = false;
		}
		if(flag) cnt++;
	}
	cout << cnt << endl;
}