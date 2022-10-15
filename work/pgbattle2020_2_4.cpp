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

int main() {
	//ドミノ敷き詰め問題(蟻本p179) O(2^min(H, W) * HW)
	ll h, w; cin >> h >> w;
	if(w > h) swap(h, w);
	vector<vector<vector<mint>>> dp(h + 1, vector<vector<mint>> (w + 1, vector<mint>(1 << w))); //dp[i][j][msk] : マス(i, j) に状態mskであるときの通り数 ただし(i, j)より前は全て埋め終わっているとする
	dp[0][0][0] = 1;
	rep(i, h) rep(j, w) rep(used, 1ll << w) {
		if(used & 1 << j) { //既に置いてある
			ll nxt = used & ~(1 << j); //既にマスが埋まっているので、自明に横にマスを置くことができない(=右隣りのマスは必ず空く)。なので、次の状態では必ず今の地点にマスを置くことができるので、その状態に遷移する。
			if(j + 1 < w) dp[i][j + 1][nxt] += dp[i][j][used];
			else dp[i + 1][0][nxt] += dp[i][j][used];
		}
		else{
			//横向き
			//マス(i,j)とマス(i,j+1)が空いていれば、マスを置ける。置くと右隣りのマスは埋まるので、その状態に遷移する。
			if(j + 1 < w && !(used & 1 << (j + 1))) dp[i][j + 1][used | 1 << (j + 1)] += dp[i][j][used];
			
			//縦向き
			//マス(i, j + 1)は必ず空いているので、マスを置ける。縦に置くとブロックが置かれていないエリアにブロックを置いていることになるが、次の状態でもその縦置きが維持されるので、問題ない(最後の行で縦置きができないのは、縦置きの状態を持っておけないから)
			if(i + 1 < h) {
				if(j + 1 < w) dp[i][j + 1][used | 1 << j] += dp[i][j][used];
				else dp[i + 1][0][used | 1 << j] += dp[i][j][used];
			}
		}
	}
	//rep(i, h) rep(j, w) rep(k, 1ll << w) cout << i << " " << j << "  " << bitset<4>(k) << "  " << dp[i][j][k].val() << endl;
	cout << bitset<4>(1 << w - 1) << endl;
	cout << dp[h - 1][w - 1][1 << w - 1].val() << endl;
}