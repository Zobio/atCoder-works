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
#define MOD 1000000007LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

/*
    問題
	選択肢の数が2N - 1、長さがKのあみだくじがある。
	ジェームズ君は以下のような仕組みに従ってあみだくじを作成した。
	開始点から見て上から距離1ごとに(距離1 ~ K)、それぞれの線分の間に横線を引くかどうかをランダムに決める。
	具体的には、サイコロを振って奇数なら横線を引いて、偶数なら引かない。この操作を全ての隣り合う線分について行う。
	やっとの思いであみだくじを作り上げたジェームズ君は左からN番目の選択肢を選んだのだが、その時手元のインクをこぼしてしまいあみだくじの内容がわからなくなってしまった。
	このとき、到達点として最も可能性の高い点を出力せよ。全て同じ場合は-1を出力せよ。

	制約
	1 <= N <= 10^3
	1 <= K <= 10^4
*/

int main() {
	ll n, k; cin >> n >> k;
	vector<vector<long double>> dp(k + 1, vector<long double>(2 * n + 2));
	//dp[i][j] ... 開始点から上から距離iで、(最初に左からN番目を選んだ時)左からj番目になる確率
	dp[0][n] = 1.0;
	for(ll i = 0; i < k; i++) {
		for(ll j = 0; j <= 2 * n + 1; j++) {
			if(j != 0 && j != 2 * n + 1) {
				dp[i + 1][j - 1] += dp[i][j] / 3.0;
				dp[i + 1][j] += dp[i][j] / 3.0;
				dp[i + 1][j + 1] += dp[i][j] / 3.0;
			}
			else if(j == 0) {
				dp[i + 1][j] += dp[i][j] / 2.0;
				dp[i + 1][j + 1] += dp[i][j] / 2.0;
			}
			else if(j == 2 * n + 1) {
				dp[i + 1][j - 1] += dp[i][j] / 2.0;
				dp[i + 1][j] += dp[i][j] / 2.0;
			}
		}
		rep(j, 2 * n + 1) printf("%.12Lf\n", dp[i][j]);
		cout << endl;
	}
	long double sum = 0;
	rep(i, 2 * n + 1) 	printf("%.12Lf\n", dp[k][i]), sum += dp[k][i];
	printf("Equally possible : %.12Lf\n", 1.0l / (2 * n + 1));
	printf("%.12Lf\n", sum);
}