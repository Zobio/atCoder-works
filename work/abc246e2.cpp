#include <bits/stdc++.h>
#include <atcoder/all> // AtCoder
using namespace std;
using namespace atcoder; // AtCoder
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using mint = modint998244353; // AtCoder
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vvvll = vector<vector<vector<long long>>>;
using vvvvll = vector<vector<vector<vector<long long>>>>;
using vbl = vector<bool>;
using vvbl = vector<vector<bool>>;
using vvvbl = vector<vector<vector<bool>>>;
using vvvvbl = vector<vector<vector<vector<bool>>>>;
using dll = deque<long long>;
using ddll = deque<deque<long long>>;
using dddll = deque<deque<deque<long long>>>;
using ddddll = deque<deque<deque<deque<long long>>>>;
using pll = pair<long long, long long>;
using vpll = vector<pair<long long, long long>>;
using vvpll = vector<vector<pair<long long, long long>>>;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define reep(i, a, b) for (long long i = a; i < b; i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define PI acos(-1.0)
#define YES printf("Yes\n"), exit(0)
#define NO printf("No\n"), exit(0)
constexpr long long MOD = 998244353LL;
constexpr long long INF = (1LL << 60);
template<class T> void setcout(T n) {cout << setprecision(n) << fixed;}
template<class T> void arrcout(T &a) { for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl; }
template<class T> void arrcout2(T &a) { for(size_t i = 0; i < a.size(); i++) { for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} }
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

vll dy = {1, -1, 1, -1};
vll dx = {1, 1, -1, -1};

int main() {
	ll n; cin >> n;
	ll sy, sx, ty, tx; cin >> sy >> sx >> ty >> tx; sy--; sx--; ty--; tx--;
	if((sy + sx & 1) != (ty + tx & 1)) cout << -1 << endl, exit(0);
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vvvll dist(n, vvll(n, vll(4, INF)));
	deque<pair<pll, ll>> dq;
	auto check = [&] (ll p1, ll p2) {
		return p1 >= 0 && p1 < n && p2 >= 0 && p2 < n && s[p1][p2] == '.';
	};
	rep(i, 4) { //初期値
		ll ny = sy + dy[i], nx = sx + dx[i];
		if(check(ny, nx)) {
			dist[ny][nx][i] = 1;
			dq.push_back({{ny, nx}, i});
		}
	}
	while(dq.size()) {
		ll y = dq.front().first.first, x = dq.front().first.second, type = dq.front().second;
		dq.pop_front();
		if(y == ty && x == tx) cout << dist[ty][tx][type] << endl, exit(0);
		rep(i, 4) {
			ll ny = y + dy[i], nx = x + dx[i];
			if(check(ny, nx)) {
				if(i == type) {
					if(chmin(dist[ny][nx][i], dist[y][x][i])) dq.push_front({{ny, nx}, i});
				}else{
					if(chmin(dist[ny][nx][i], dist[y][x][type] + 1)) dq.push_back({{ny, nx}, i});
				}
			}
		}
	}
	cout << -1 << endl;
}