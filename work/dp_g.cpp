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

vector<long long> TopologicalSort (ll siz, vvll pri) {
    /*
    順番指定priに従ってトポロジカルソートされた頂点数sizの順列を返す関数
	複数通りある場合、辞書順で最小のものを返す
    */
    priority_queue<ll, vector<ll>, greater<ll>> pq;
	vll cnt(siz);
    rep(i, siz) rep(j, pri[i].size()) cnt[pri[i][j]]++;
    rep(i, siz) if(cnt[i] == 0) pq.push(i);
    vll ret;
    while(!pq.empty()) {
		ll now = pq.top(); pq.pop();
		ret.push_back(now);
		for(auto a : pri[now]) {
			cnt[a]--;
			if(cnt[a] == 0)pq.push(a);
		}
	}
    return ret; //ret.size() == sizでなければトポロジカルソートできていない
}

int main() {
	ll n, m; cin >> n >> m;
	vvll g;
	g.resize(n);
	rep(i, m) {
		ll a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
	}
	vll ts = TopologicalSort(n, g);
	vll dp(n);
	for(auto cur : ts) for(auto to : g[cur]) chmax(dp[to], dp[cur] + 1);
	cout << *max_element(all(dp)) << endl;
}