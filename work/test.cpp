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

ll n, m, cnt = 0;
vvll g, h;
vll used, nums;

void dfs(ll pos) {
	used[pos] = true;
	for (int i : g[pos]) {
		if (used[i] == false) dfs(i);
	}
	nums.push_back(pos);
}

void dfs2(ll pos) {
	used[pos] = true;
	cnt++;
	for(ll i : h[pos]) {
		if(!used[i]) dfs2(i);
	}
}

int main() {
	cin >> n >> m; //頂点、辺
	g.resize(n); h.resize(n);
	rep(i, m) {
		ll a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		h[b].push_back(a);
	}
	used.resize(n);
	rep(i, n) if(!used[i]) dfs(i); //first DFS

	reverse(all(nums));
	fill(all(used), 0); //帰りがけ順に番号を記録しているので、逆にすると強連結についてDFSできる

	ll ans = 0;
	for(ll i : nums) {
		if(used[i]) continue;
		cnt = 0;
		dfs2(i);
		ans += cnt * (cnt - 1) / 2;
	}
	cout << ans << endl;
}