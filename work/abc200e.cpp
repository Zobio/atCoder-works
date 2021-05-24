#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main() {
	ll n, k;
	cin >> n >> k;
	vector<vector<ll>> dp(4, vector<ll>(3000010));
	vector<vector<ll>> cum(4, vector<ll>(3000010));
	dp[0][0] = 1;
	for(int i = 1; i < 3 * n + 2; i++) 
		cum[0][i] = 1;
	for(ll i = 1; i <= 3; i++) {
		for(ll j = 0; j < 3 * n + 1; j++)
			dp[i][j] = cum[i - 1][j] - cum[i - 1][max((ll)0, j - n)]; //dp
		for(ll j = 0; j < 3 * n + 1; j++)
			cum[i][j + 1] = cum[i][j] + dp[i][j]; //累積和をとる
	}
	ll sum = 1;
	while (dp[3][sum] < k)
	{
		cout << sum << " " << dp[3][sum] << endl;
		k -= dp[3][sum];
		sum++;
	}
	//「綺麗さ」を求める
	ll i1 = 1;
	while (dp[2][sum - i1] < k)
	{
		k -= dp[2][sum - i1];
		i1++;
	}

	//「おいしさ」を求める
	ll i2 = 1;
	while (dp[1][sum - i1 - i2] < k)
	{
		k -= dp[1][sum - i1 - i2];
		i2++;
	}

	cout << i1 << " " << i2 << " " << sum - i1 - i2 << endl;
}