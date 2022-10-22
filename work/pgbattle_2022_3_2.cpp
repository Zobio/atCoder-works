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

int main() {
	ll w, h, t; cin >> w >> h >> t;
	ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
	ll my = ty - sy, mx = tx - sx;
	
	set<ll> dy, dx;
	if(my >= 0) {
		if(my <= t)dy.insert(my);
		for(ll i = 0, dist = my + 2 * (h - ty); dist <= t; i++, dist += (i & 1 ? 2 * ty: 2 * (h - ty))) dy.insert(dist);
		if(2 * ty + my <= t) dy.insert(-(2 * sy + my));
		for(ll i = 0, dist = 2 * sy + my; dist <= t; i++, dist += (i & 1 ? 2 * (h - ty): 2 * ty)) dy.insert(-dist);
	}else{
		if(-my <= t)dy.insert(my);
		for(ll i = 0, dist = -my + 2 * ty; dist <= t; i++, dist += (i & 1 ? 2 * (h - ty): 2 * ty)) dy.insert(-dist);
		if(2 * (h - sy) + -my <= t) dy.insert(2 * (h - ty) + -my <= t);
		for(ll i = 0, dist = 2 * (h - sy) + -my <= t; dist <= t; i++, dist += (i & 1 ? 2 * (h - ty): 2 * ty)) dy.insert(dist);
	}
	if(mx >= 0) {
		if(mx <= t) dx.insert(mx);
		for(ll i = 0, dist = mx + 2 * (w - tx); dist <= t; i++, dist += (i & 1 ? 2 * tx : 2 * (w - tx))) dx.insert(dist);
		if(2 * sx + mx <= t) dx.insert(-(2 * sx + mx));
		for(ll i = 0, dist = 2 * sx + mx; dist <= t; i++, dist += (i & 1 ? 2 * (w - tx) : 2 * tx)) dx.insert(-dist);
	}else{
		if(-mx <= t)dx.insert(mx);
		for(ll i = 0, dist = -mx + 2 * tx; dist <= t; i++, dist += (i & 1 ? 2 * (w - tx): 2 * tx)) dx.insert(-dist);
		if(2 * (w - sx) + -mx <= t) dx.insert(2 * (w - tx) + -mx);
		for(ll i = 0, dist = 2 * (w - sx) + -mx <= t; dist <= t; i++, dist += (i & 1 ? 2 * (w - tx): 2 * tx)) dx.insert(dist);
	}
	ll ans = 0;
	for(auto yy : dy) for(auto xx : dx) if(yy * yy + xx * xx == t * t) ans++;
	cout << ans << endl;
}