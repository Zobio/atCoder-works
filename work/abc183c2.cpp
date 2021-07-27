#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	ll k;
	cin >> n >> k;
	vector<vector<ll>> t(n, vector<ll>(n));
	rep(i, n) rep(j, n) cin >> t[i][j];
	vector<int> ro(n);
	rep(i, n) ro[i] = i;
	ll ans = 0;
	do {
		if(ro[0] != 0) continue;
		ll sum = 0;
		rep(i, n - 1) sum += t[ro[i]][ro[i + 1]];
		sum += t[ro[n - 1]][ro[0]];
		ans += sum == k;
	}while(next_permutation(ro.begin(), ro.end()));
	cout << ans << endl;
}