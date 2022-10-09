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
	ll n, k; cin >> n >> k;
	vll a(n), b(n); rep(i, n) cin >> a[i] >> b[i], a[i]--, b[i]--;
	ll ma_a = *max_element(all(a)), ma_b = *max_element(all(b));
	vvll cnt(ma_a + 1, vll(ma_b + 1));
	rep(i, n) cnt[a[i]][b[i]]++;
	vvll rui(ma_a + 1 + 1, vll(ma_b + 1 + 1));
	rep(i, ma_a + 1) rep(j, ma_b + 1) {
		rui[i + 1][j + 1] = rui[i + 1][j] + rui[i][j + 1] - rui[i][j] + cnt[i][j];
	}
	ll ans = 0;
	rep(i, ma_a + 2) rep(j, ma_b + 2) {
		ll p = max(i - k - 1, 0ll), q = max(j - k - 1, 0ll);
		chmax(ans, rui[i][j] - rui[p][j] - rui[i][q] + rui[p][q]);
	}
	cout << ans << endl;
}