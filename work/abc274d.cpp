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

ll fix = 10005;

int main() {
	ll n, x, y; cin >> n >> x >> y;
	x += fix; y += fix;
	vll a(n); rep(i, n) cin >> a[i];
	vll yoko, tate;
	for(ll i = 1; i < n; i++) (i & 1 ? tate : yoko).push_back(a[i]);
	ll ts = tate.size(), ys = yoko.size();
	vvll dp_y(ts + 1, vll(20200)), dp_x(ys + 1, vll(20200));
	dp_y[0][fix] = 1; dp_x[0][fix + a.front()] = 1;

	rep(i, ts) rep(j, dp_y[i].size()) {
		if(!dp_y[i][j]) continue;
		if(j + tate[i] <= dp_y[i + 1].size() - 1) dp_y[i + 1][j + tate[i]] = true;
		if(j - tate[i] >= 0) dp_y[i + 1][j - tate[i]] = true;
	}
	rep(i, ys) rep(j, dp_x[i].size()) {
		if(!dp_x[i][j]) continue;
		if(j + yoko[i] <= dp_x[i + 1].size() - 1) dp_x[i + 1][j + yoko[i]] = true;
		if(j - yoko[i] >= 0) dp_x[i + 1][j - yoko[i]] = true;
	}
	cout << (dp_x.back().at(x) && dp_y.back().at(y) ? "Yes" : "No") << endl;
}