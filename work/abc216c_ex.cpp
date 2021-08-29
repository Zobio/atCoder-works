#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

/*
問題
空の箱があります。
髙橋君は以下の 2 種類の魔法を好きな順番で好きな回数使えます。

魔法 A ：箱の中にボールを 1 つ増やす
魔法 B ：箱の中のボールの数を 2 倍にする
箱の中のボールの数をちょうど N 個にする方法が何通りあるかを求めなさい。
解は大きくなる可能性があるので、1000000007で割った値を出力すること。

制約
1 ≤ N ≤ 10^6
 
入力は全て整数
*/

void solve1(ll n) {
	vector<ll> dp(n + 1); //dp[i] ... iまでの通り数(∴答えはdp[n])
	dp[0] = 1;
	for(ll i = 1; i <= n; i++) {
		if(i & 1) dp[i] = dp[i - 1];
		else dp[i] = (dp[i - 1] + dp[i / 2]) % MOD;
	}
	cout << dp[n] << endl;
}

void solve2(ll n) {
	vector<ll> dp(n + 1); //dp[i] ... iまでの通り数(∴答えはdp[n])
	dp[0] = 1;
	for(ll i = 0; i < n; i++) {
		dp[i + 1] = (dp[i] + dp[i + 1]) % MOD;
		if((i << 1) <= n) dp[i << 1] = (dp[i << 1] + dp[i]) % MOD;
	}
	cout << dp[n] << endl;
}

int main() {
	ll n; cin >> n;
	solve1(n);
	solve2(n);
}