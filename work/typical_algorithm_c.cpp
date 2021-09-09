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
vector<vector<ll>> dp; // dp[i][j]頂点集合iが訪問済みで、今jにいるときの重さの総和の最小値(∴答えはdp[1 << n][k](k = 1 ~ N)の最小値)

ll solve(ll S, ll v) {
	cout << bitset<4>(S) << " " << v << endl;
	if(dp[S][v] != -1) return dp[S][v];

	ll state = S & ~(1 << v); //頂点集合Sからvを取り除く
	ll res = INF;
	rep(i, n) {
		if(!(state & (1 << i))) continue; //stateは"すでに訪問した"頂点集合なので該当しないものはcontinue
		res = min(res, solve(state, i) + a[i][v]); 
	}
	cout << bitset<4>(S) << " " << v << " " << res << endl;
	return dp[S][v] = res;
}

int main() {
	cin >> n;
	a.assign(n, vector<ll>(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	dp.assign(1 << n, vector<ll>(n, -1));
	rep(i, n) dp[1 << i][i] = 0; //初期値(初期値点しか訪問していないから0)
	ll ans = INF;
	rep(i, n) ans = min(ans, solve((1 << n) - 1, i));
	cout << endl;
	rep(i, n) cout << i << " " << solve((1 << n) - 1, i) << endl;
	cout << ans << endl;
}