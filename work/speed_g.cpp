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

int main() {
	ll n, m; cin >> n >> m;
	vvll g(n, vll(n));
	rep(i, m) {
		ll a, b; cin >> a >> b; a--; b--;
		g[a][b] = g[b][a] = true;
	}
	vvll a(n - 1, vll(n));
	rep(i, n - 1) rep(j, n) cin >> a[i][j];
	vvll dp(n, vll(1ll << n));	//dp[i][j] ... i日目に部屋集合jを部室にしているときの嬉しさの最大値(∴答えはdp[n-1][(1 << n) - 1])
	rep(i, n - 1) rep(j, 1 << n) rep(k, n) { //i日目、部屋集合jにに部屋kを追加する、
		if(j & (1 << k)) continue; //もうその部屋を部室にしていたらcontinue
		if(bitset<20>(j).count() != i) continue; //部屋の数が適していなかったらcontinue
		ll cnt = 0, flag = 0; 
		rep(l, n) {
			if(g[k][l] && (j & (1 << l))) flag = true;
		}
		if(g[0][k]) flag = true;
		if(!flag) continue; //部屋集合jと部屋kがつながっていなかったらcontinue
		if(dp[i][j] == 0 && i != 0) continue;
		chmax(dp[i + 1][j | (1 << k)], dp[i][j] + a[i][k]);
	}
	cout << dp[n - 1][(1 << n) - 2] << endl;
}