#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m; cin >> n >> m;
	vector<int> like(m, 0);
	rep(i, n) {
		int k; cin >> k;
		rep(j, k) {
			int tmp; cin >> tmp; tmp--;
			like[tmp]++;
		}
	}
	int ans = 0;
	rep(i, m) if(like[i] == n) ans++;
	cout << ans << endl;
}