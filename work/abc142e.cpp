#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

ll n, m;
vector<vector<ll>> dp;
vector<ll> a;
vector<ll> b;
vector<ll> tre;

int main() {
	cin >> n >> m;
	dp.resize(m + 1, vector<ll>(1LL << n, INF)); //dp[i][msk] ... 鍵iまでを使って集合mskをあけるのに必要なコストの最小値
	a.resize(m); b.resize(m); tre.resize(m, 0);
	rep(i, m) {
		cin >> a.at(i) >> b.at(i);
		rep(j, b[i]) {
			ll c; cin >> c; c--;
			tre[i] |= 1ll << c;
		}
	}
	dp[0][0] = 0;

	rep(i, m) rep(j, 1ll << n) {
		dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
		dp[i + 1][j | tre[i]] = min(dp[i + 1][j | tre[i]], dp[i + 1][j] + a[i]);
	}

	cout << (dp[m][(1 << n) - 1] == INF ? -1 : dp[m][(1 << n) - 1]) << endl;
}