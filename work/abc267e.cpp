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

int main() {
	ll n, m; cin >> n >> m;
	vll a(n); rep(i, n) cin >> a[i];
	vvll g(n);
	rep(i, m) {
		ll u, v; cin >> u >> v; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll l = -1, r = INF; //コストの最小値を二分探索
	while(r - l > 1) {
		ll mid = l + r >> 1ll;
		vll done(n); //削除した頂点
		vll cost(n); //頂点を削除するときにかかるコスト
		rep(i, n) {
			for(auto au : g[i]) cost[i] += a[au];
		}
		ll cnt1 = 0, cnt2 = 0;
		stack<ll> s; rep(i, n) if(cost[i] <= mid) s.push(i);
		while(!s.empty()) {
			ll cur = s.top(); s.pop();
			if(done[cur]) continue;
			done[cur] = true;
			for(auto au : g[cur]) {
				cost[au] -= a[cur];
				if(cost[au] <= mid && !done[au]) s.push(au);
			}
		}
		if(accumulate(all(done), 0ll) == n) r = mid;
		else l = mid;
	}
	cout << r << endl;
}