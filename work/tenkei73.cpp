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
#define MOD 1000000007LL
#define mint modint1000000007
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll n;
vll c;
vvll g, done;
vector<vector<mint>> dp;

void dfs(ll cur, ll state) {
	done[cur][state] = true;
	bool leaf = true;
	for(auto nxt : g[cur]) {
		rep(i, 3) if(!done[nxt][i]) leaf = false, dfs(nxt, i);
	}
	rep(i, 3) {
		mint q = 1;
		for(auto nxt : g[cur]) {
			if(i != 2) {
				q *= dp[nxt][i] + dp[nxt][2]; //辺を削除しない+辺を削除する
			}else{
				q *= (dp[nxt][0] + dp[nxt][1] + dp[nxt][2]) + dp[nxt][2]; //辺を削除しない+辺を削除する-包除分
			}
		}
		dp[cur][i] = q - (i == 2 ? dp[cur][c[cur]] : 0);
	}
	if(leaf) dp[cur][state] += state == c[cur];
	cout << cur << " " << state << "  : " << dp[cur][state].val() << endl;
}

int main() {
	//木DP
	cin >> n;
	c.resize(n);
	rep(i, n) {
		char s; cin >> s; c[i] = s == 'a' ? 0 : 1;
	}
	g.resize(n); done.resize(n, vll(3));
	rep(i, n - 1) {
		ll a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b); g[b].push_back(a);
	}
	dp.resize(n, vector<mint>(3)); //dp[i][j] : 頂点iの部分木で状態がjのときの通り数(部分木にaのみ-->j=0, 部分木にbのみ-->j=1, 両方-->j=2)
	dfs(0, 2);
	rep(i, n) rep(j, 3) cout << i << " " << j << "  : " << dp[i][j].val() << endl;
	cout << dp.back().back().val() << endl;
}