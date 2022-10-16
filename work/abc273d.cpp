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
	ll h, w, sy, sx; cin >> h >> w >> sy >> sx; sy--; sx--;
	ll n; cin >> n;
	vpll r(n); rep(i, n) cin >> r[i].first >> r[i].second, r[i].first--, r[i].second--;
	ll q; cin >> q;
	vector<char> d(q); vll l(q); rep(i, q) cin >> d[i] >> l[i];
	map<ll, set<ll>> w_yoko, w_tate, rv_yoko, rv_tate; //横についての壁の座標しゅうごう、縦
	rep(i, n) w_yoko[r[i].first].insert(r[i].second), rv_yoko[r[i].first].insert(-r[i].second);
	rep(i, n) w_tate[r[i].second].insert(r[i].first), rv_tate[r[i].second].insert(-r[i].first);
	ll y = sy, x = sx;
	rep(i, q) {
		ll len = l[i];
		if(d[i] == 'R') {
			auto it = w_yoko[y].upper_bound(x);
			if(it == w_yoko[y].end()) x = min(x + len, w - 1);
			else x = min(x + len, *it - 1);
		}
		else if(d[i] == 'D') {
			auto it = w_tate[x].upper_bound(y);
			if(it == w_tate[x].end()) y = min(y + len, h - 1);
			else y = min(y + len, *it - 1);
		}
		else if(d[i] == 'L') {
			auto it = rv_yoko[y].upper_bound(-x);
			if(it == rv_yoko[y].end()) x = max(x - len, 0ll);
			else x = max(x - len, -*it + 1);
		}
		else if(d[i] == 'U') {
			auto it = rv_tate[x].upper_bound(-y);
			if(it == rv_tate[x].end()) y = max(y - len, 0ll);
			else y = max(y - len, -*it + 1);
		}
		cout << y + 1 << " " << x + 1 << endl;
	}
}