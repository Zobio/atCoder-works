#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll h, w;
vector<string> c;
vvll dp;

void f(ll y, ll x) {
	if(y != h - 1) chmin(dp[y][x], dp[y + 1][x] + (c[y][x] == 'E'));
	if(x != w - 1) chmin(dp[y][x], dp[y][x + 1] + (c[y][x] == 'S'));
	
	if(y != 0) f(y - 1, x);
	else if(x != 0) f(h - 1, x - 1);
}

int main() { //満点解法
	cin >> h >> w;
	c.resize(h);
	rep(i, h) cin >> c[i];
	dp.resize(h, vll(w, INF)); // dp[i][j] ... (i, j)から(h - 1, w)へ到達するときに変更しなければならないマスの最小数(∴答えはdp[0][0])
	dp[h - 1][w - 1] = c[h - 1][w - 1] == 'S' ? 1 : 0; //初期値
	f(h - 1, w - 1);
	cout << dp[0][0] << endl;
}