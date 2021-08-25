#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define arrcout(a) for(int i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007LL
#define INF 1LL << 60

ll n, m, q;
vector<vector<ll>> a;
vector<ll> arr;
ll ans = 0;

void dfs(int now) {
	if(now == n) {
		ll cnt = 0;
		rep(i, q) {
			if(arr[a[i][1]] - arr[a[i][0]] == a[i][2]) {
				cnt += a[i][3];
			}
		}
		ans = max(ans, cnt);
		return;
	}
	for(ll i = (now == 0 ? 1 : arr[now - 1]); i <= m; i++) {
		arr[now] = i;
		dfs(now + 1);
	}
}

int main() {
	cin >> n >> m >> q;
	a.resize(q, vector<ll>(4));
	arr.resize(n);
	rep(i, q) {
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
		a[i][0]--; a[i][1]--;
	}
	dfs(0);
	cout << ans << endl;
}