#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n; cin >> n;
	vll a(n), b(n);
	rep(i, n) cin >> a.at(i); rep(i, n) cin >> b.at(i);
	vvll dp(n + 1, vll(3010));
	dp[0][0] = 1;
	rep(i, n) {
		ll sum = 0, before = 0;
		for(ll j = a[i]; j <= b[i]; j++) {
			for(ll k = before; k <= j; k++) {
				//ここはj == a[i]の時a[i]回回り、それ以外の時は高々1回しか回らない
				sum = (sum + dp[i][k]) % MOD;
			} 
			dp[i + 1][j] = sum;
			before = j + 1;
		}
	}
	ll ans = 0;
	rep(i, dp[n].size()) ans = (ans + dp[n][i]) % MOD;
	cout << ans << endl;
}