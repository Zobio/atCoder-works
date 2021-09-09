#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

ll n;
vector<vector<ll>> a;
vector<vector<ll>> dp; // dp[i][j]頂点集合iが訪問済みで、今jにいるときここから頂点0に戻るのに必要な重さの総和の最小値(∴ans = dp[0][0])

ll solve(ll S, ll v) {
	if(dp[S][v] != -1) return dp[S][v];

	if(S == (1 << n) - 1 && v == 0) {
		return dp[S][v] = 0; //全ての頂点を訪れて戻ってきた
	}
	ll res = INF;
	rep(i, n) {
		if(!((S >> i) & 1)) res = min(res, solve(S ^ (1 << i), i) + a[v][i]);
	}
	return dp[S][v] = res;
}

int main() {
	cin >> n;
	a.assign(n, vector<ll>(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	dp.assign(1 << n, vector<ll>(n, -1));
	cout << solve(0, 0) << endl;
}