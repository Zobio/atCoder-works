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

ll w, h, t;
ll sx, sy, tx, ty;
ll ma = 200010;
map<ll, ll> sq;

ll check(ll x, ll y, ll rx, ll ry) {
	x = (x % (2 * w) + (2 * w)) % (2 * w);
	y = (y % (2 * h) + (2 * h)) % (2 * h);
	if(x == rx && y == ry) return 1;
	else return 0;
}

ll calc(ll rx, ll ry) {
	ll ret = 0;
	for(ll x = -t; x <= t; x++){
		ll r = t * t - x * x;
		if(sq.count(r) == 0) continue; //平方数でない
		ll y = sq[r];
		ret += check(sx + x, sy + y, rx, ry);
		if(y != 0) ret += check(sx + x, sy - y, rx, ry); //y==0は二重計算になるので除外
	}
	return ret;
}

int main() {
	cin >> w >> h >> t;
	cin >> sx >> sy >> tx >> ty;
	rep(i, ma) sq[i * i] = i;

	ll ans = 0;
	ans += calc(tx, ty);
	ans += calc(tx, 2 * h - ty);
	ans += calc(2 * w - tx, ty);
	ans += calc(2 * w - tx, 2 * h - ty);

	cout << ans << endl;
}