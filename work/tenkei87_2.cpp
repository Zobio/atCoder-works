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

void calc_dist(ll w) {
	dist.assign(n, vll(n, INF));
	rep(i, n) rep(j, n) dist[i][j] = a[i][j] != -1 ? a[i][j] : w;
	rep(i, n) reep(j, i + 1, n) reep(l, j + 1, n) {
		chmin(dist[j][k], dist[j][i] + dist[i][k]);
	}
}

int main() {
	cin >> n >> p >> k;
	a.resize(n, vll(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	ll l = 0, r = INF;
	while(r - l > 1) {
		ll mid = l + r >> 1;
		calc_dist(mid);
		ll cnt = 0;
		rep(i, n) reep(j, i + 1, n) cnt += dist[i][j] <= p;
		if(cnt < k) r = mid;
		else l = mid;
	}
	ll ans_high = l;
	l = 0, r = INF;
	while(r - l > 1) {
		ll mid = l + r >> 1;
		calc_dist(mid);
		ll cnt = 0;
		rep(i, n) reep(j, i + 1, n) cnt += dist[i][j] <= p;
		if(cnt <= k) r = mid;
		else l = mid;
	}
	ll ans_low = r;
	ll ma = INF - 10;
	cout << ans_high << " " << ans_low << endl;
	if(ans_high > ma && ans_low > ma) cout << 0 << endl;
	else if(ans_high > ma) cout << "Infinity" << endl;
	else cout << ans_high - ans_low + 1 << endl;
}