#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int n;
ll k;
ll ans = 0;
vector<vector<ll>> t;

void dfs(int p, ll sum, vector<bool>done, int cnt) {
	if(p == 0 && cnt == n) {
		ans += sum == k;
		return;
	}
	done[p] = true;
	for(int i = 0; i < n; i++) {
		//cout << "p: " << p << " i: " << i << endl;
		if(!done[i] || (i == 0 && cnt == n - 1)) {
			cnt++;
			//cout << p << " --> " << i << " " << sum + t[p][i] << " " << cnt << endl;
			dfs(i, sum + t[p][i], done, cnt);
			cnt--;
		}
	}
}

int main() {
	cin >> n >> k;
	t.resize(n, vector<ll>(n));
	vector<bool> done(n, false);
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> t[i][j];
	dfs(0, 0, done, 0);
	cout << ans << endl;
}