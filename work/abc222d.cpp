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
	//dp[i][j] ... i番目までで1番後の数字がjであるときの通り数(∴答えはΣ(k=0~3000)dp[n][k])
	vvll rui(n + 1, vll(3010));
	rep(i, n) {
		rep(j, 3001) {
			if(a[i] > j || b[i] < j) {
				dp[i + 1][j] = 0;
				rui[i + 1][j + 1] = rui[i + 1][j];
				continue;
			}
			dp[i + 1][j] = j ? rui[i + 1][j] + 1 : 1;
			rui[i + 1][j + 1] = (rui[i + 1][j] + dp[i + 1][j]) % MOD;
			cout << i+1 << " " << j << " " <<  dp[i + 1][j] << endl;
		}
	}
	cout << rui[n][3000] << endl;
}