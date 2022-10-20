#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define reep(i, a, b) for(long long i = a; i < b; i++)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define dll deque<long long>
#define ddll deque<dque<long long>>
#define dddll deque<deque<deque<long long>>>
#define ddddll deque<deque<deque<deque<long long>>>>
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;}
#define setcout(n) cout << setprecision(n) << fixed
#define YESS {printf("Yes\n"); return 0;}
#define NOO {printf("No\n"); return 0;}
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define mint modint998244353
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll n;
vll cnt(3);
vector<vector<vector<bool>>> done;
vector<vector<vector<ld>>> dp;

ld dfs(ll c1, ll c2, ll c3) {
	if(done[c1][c2][c3]) return dp[c1][c2][c3];

	ld cur = 0;
	if(c1 > 0) cur += dfs(c1 - 1, c2, c3) * (c1 / (ld)n);
	if(c2 > 0 && c1 + 1 <= n) cur += dfs(c1 + 1, c2 - 1, c3) * (c2 / (ld)n);
	if(c3 > 0 && c2 + 1 <= n) cur += dfs(c1, c2 + 1, c3 - 1) * (c3 / (ld)n);
	cur += 1.0;	//今回の行動分
	cur /= 1.0 - (n - (c1 + c2 + c3)) / (ld)n; // 1-(0個の皿が選ばれる確率)
	done[c1][c2][c3] = true;
	return dp[c1][c2][c3] = cur;
}

int main() {
	setcout(15);
	cin >> n;
	rep(i, n) {
		ll a; cin >> a; a--; cnt[a]++;
	}
	done.resize(n + 1, vector<vector<bool>>(n + 1, vector<bool>(n + 1)));
	dp.resize(n + 1, vector<vector<ld>>(n + 1, vector<ld>(n + 1))); // dp[i][j][k] : 1個の皿がi,2個の皿がj,3個の皿がk枚残っているときの操作回数の期待値
	dp.front().front().front() = 0; done.front().front().front() = true;
	cout << dfs(cnt[0], cnt[1], cnt[2]) << endl;
}