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
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define PI 3.141592653589793238
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ld t, l, x, y; cin >> t >> l >> x >> y;
	ll q; cin >> q;
	setcout(10);
	rep(_, q) {
		ld e; cin >> e;
		ld cx = 0; //観覧車のx座標
		ld cy = -(l / 2.0) * sin(e / t * 2.0 * PI); //観覧車のy座標
		ld cz = (l / 2.0) - (l / 2.0) * cos(e / t * 2.0 * PI); //観覧車のz座標
		ld d1 = sqrt((cx - x) * (cx - x) + (cy - y) * (cy - y)); //像と観覧車の水平距離
		ld d2 = cz; //像と観覧車の垂直距離(∵像の高さは0)
		ld angle = atan2(d2, d1); //ラジアン
		cout << angle * 180.0L / PI << endl;
	}
}