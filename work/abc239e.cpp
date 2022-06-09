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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll n, q;
vll x;
vvll g;
vvll ans;

void dfs(ll cur, ll pre) { //Euler Tourしながら配列を生成
	ans[cur].push_back(x[cur]); //自分の頂点に書かれている数字を追加
	for(auto au : g[cur]) if(au != pre) {
		dfs(au, cur); //葉の配列を確定させる
		ans[cur].insert(ans[cur].end(), all(ans[au]));//葉の配列を追加
	}
	sort(rall(ans[cur]));
	if(ans[cur].size() > 20) ans[cur].resize(20);
}

int main() {
	cin >> n >> q;
	x.resize(n); rep(i, n) cin >> x[i];
	g.resize(n); ans.resize(n);
	rep(i, n - 1) {
		ll a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b); g[b].push_back(a);
	}
	dfs(0, -1);
	rep(_, q) {
		ll v, k; cin >> v >> k; v--; k--;
		cout << ans[v][k] << endl;
	}
}