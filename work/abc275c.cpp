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
	vector<string> s(9); rep(i, 9) cin >> s[i];
	ll ans = 0;
	rep(i, 81) reep(j, i + 1, 81) {
		ll y1 = i / 9, x1 = i % 9;
		ll y2 = j / 9, x2 = j % 9;
		if(x1 >= x2) continue; //左上、右下の点になるように調整
		if(s[y1][x1] == '.' || s[y2][x2] == '.') continue;
		ll dy = y2 - y1, dx = x2 - x1;
		ll y3 = y1 + dx, x3 = x1 - dy;
		ll y4 = y2 + dx, x4 = x2 - dy;
		if(x3 < 0 || x3 >= 9 || y3 < 0 || y3 >= 9) continue;
		if(x4 < 0 || x4 >= 9 || y4 < 0 || y4 >= 9) continue;
		ans += s[y3][x3] == '#' && s[y4][x4] == '#';
	}
	cout << ans << endl;
}