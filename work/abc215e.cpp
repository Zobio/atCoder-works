#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 998244353LL
#define INF 1LL << 60

int main() {
	int n; string s; cin >> n >> s;
	ll ans = 1;
	rep(i, n) ans = (ans * 2) % MOD;
	vector<vector<ll>> dp(n, vector<ll>(10)); //dp[i][j] ... i番目までで最後がjであったときのパターン数
	
}