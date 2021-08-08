#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(a) cout << a << endl

int main() {
	int n, m;
	cin >> n >> m;
	vector<bool> br(n, false); //その段が壊れているかを保存しておくフラグの配列
	rep(i, m) {
		int a; cin >> a;
		br[a] = true;
	}
	vector<ll> dp(n + 1); //0 ~ Nなので要素数はN + 1
	dp[1] = dp[0] = 1; //初期値
	rep(i, n - 1) {
		if(br[i + 1] && br[i]) break; //2段連続で壊れていたらそこで終了
		dp[i + 2] = ((!br[i + 1] ? dp[i + 1] : 0) + (!br[i] ? dp[i] : 0)) % MOD; 
	}
	cout << dp[n] << endl;
}