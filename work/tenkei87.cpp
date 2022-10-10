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

ll n, p, k;
vvll a, dist;

vvll bfs(ll w) {
	dist.assign(n, vll(n, INF));
	rep(st, n) {
		dist[st][st] = 0;
		queue<ll> que; que.push(st);
		while(que.size()) {
			ll cur = que.front(); que.pop();
			rep(nxt, n) if(chmin(dist[st][nxt], dist[st][cur] + (a[cur][nxt] != -1 ? a[cur][nxt] : w))) que.push(nxt);
		}
	}
	return dist;
}

int main() {
	cin >> n >> p >> k;
	a.resize(n, vll(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	ll l = 0, r = INF;
	while(r - l > 1) {
		ll mid = l + r >> 1;
		vvll d = bfs(mid);
		ll cnt = 0;
		rep(i, n) reep(j, i + 1, n) cnt += d[i][j] <= p;
		if(mid == INF - 1 && cnt != k) {cout << 0 << endl; return 0;}
		if(cnt < k) r = mid;
		else l = mid;
	}
	ll ans_high = l;
	l = 0, r = INF;
	while(r - l > 1) {
		ll mid = l + r >> 1;
		vvll d = bfs(mid);
		ll cnt = 0;
		rep(i, n) reep(j, i + 1, n) cnt += d[i][j] <= p;
		if(mid == 0 && cnt != k) {cout << 0 << endl; return 0;}
		if(cnt > k) l = mid;
		else r = mid;
	}
	ll ans_low = r;
	if(ans_high == INF - 1) {cout << "Infinity" << endl; return 0;}
	cout << ans_high - ans_low + 1 << endl;
}