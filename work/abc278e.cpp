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
	ll h, w, n, p, q; cin >> h >> w >> n >> p >> q;
	vvll a(h, vll(w)); rep(i, h) rep(j, w) cin >> a[i][j], a[i][j]--;
	vvvll rui(h + 1, vvll(w + 1, vll(n)));
	rep(i, h) rep(j, w) rep(k, n) {
		rui[i + 1][j + 1][k] = rui[i + 1][j][k] + rui[i][j + 1][k] - rui[i][j][k] + (a[i][j] == k);
	}
	/*rep(i, h) rep(j, w) rep(k, n) {
		cout << i + 1 << " " << j + 1 << " " << k + 1 << "  " << rui[i][j][k] << endl;
	}*/
	rep(i, h - p + 1) {
		rep(j, w - q + 1) {
			ll cnt = 0;
			rep(k, n) {
				cnt += rui.back().back().at(k) - (rui[i + p][j + q][k] - rui[i + p][j][k]- rui[i][j + q][k] + rui[i][j][k]) > 0;
			}
			cout << cnt << " ";
		}
		cout << endl;
	}
}