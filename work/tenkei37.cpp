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
#define MOD 998244353LL
#define mint modint998244353
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll op(ll a, ll b){ return max(a, b); }
ll e(){ return 0; }
ll mapping(ll f, ll x){ return f + x; }
ll composition(ll f, ll g){ return f + g; }
ll id(){ return 0; }

int main() {
	ll w, n; cin >> w >> n;
	vll l(n), r(n), v(n);
	rep(i, n) cin >> l[i] >> r[i] >> v[i];
	lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(w + 1);
	vvll dp(n + 1, vll(w + 1, -INF)); //dp[i][j] : i個目まで見て、香辛料の合計がjであるときの価値の最大値
	dp[0][0] = 0;

	rep(i, n) {
		rrep(j, w) {
			if(dp[i][j] == -INF) continue;
			ll cr = j;
			ll cur = dp[i][j];
			while(1) {
				if(j == 0) break;
				if(dp[i][j] != cur) break;
				j--;
			}
			ll cl = j;
			if(cl + l[i] > w) continue;
			cout << i << " " << cl << " " << cr << endl;
			seg.apply(cl + l[i] , min(cr + r[i], w) + 1, seg.get(j) + v[i]);
		}
		rep(j, w + 1) dp[i + 1][j] = max(dp[i][j] != -INF ? dp[i][j] : -INF, seg.get(j));
		cout << "seg: " << endl;rep(j, w + 1) cout << seg.get(j) << " "; cout << endl;
	}
	arrcout2(dp);
	cout << endl << endl;
	cout << "seg: " << endl;rep(i, w + 1) cout << seg.get(i) << " "; cout << endl;
	cout << seg.all_prod() << endl;
}