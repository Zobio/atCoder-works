#include <stdio.h>
#define ll long long
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define max(p, q) ((p) > (q) ? (p) : (q))

ll dp[4][3000010];
ll cum[4][3000010];
int main()
{
	ll n, k;
	scanf("%lld%lld", &n, &k);
	dp[0][0] = 1;
	rep(j, 1, 3 * n + 1 + 1) cum[0][j] = 1;

	rep(i, 1, 4)
	{
		//dp
		rep(j, 0, 3 * n + 1) dp[i][j] = cum[i - 1][j] - cum[i - 1][max(0, j - n)];
		//累積和をとる
		rep(j, 0, 3 * n + 1) cum[i][j + 1] = cum[i][j] + dp[i][j];
	}

	//「綺麗さ」＋「おいしさ」＋「人気度」を求める
	ll sum = 1;
	while (dp[3][sum] < k)
	{
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

	printf("%lld %lld %lld", i1, i2, sum - i1 - i2);
}