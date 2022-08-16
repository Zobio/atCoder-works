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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define mint modint998244353
#define INF (1LL << 60)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n, l, r; cin >> n >> l >> r;
	vll a(n); rep(i, n) cin >> a[i];
	vll rui_l(n + 1); rep(i, n) rui_l[i + 1] = rui_l[i] + a[i];
	vll les_l(n); rep(i, n) les_l[i] = rui_l[i + 1] - l * (i + 1);
	reverse(all(a));
	vll rui_r(n + 1); rep(i, n) rui_r[i + 1] = rui_r[i] + a[i];
	vll les_r(n); rep(i, n) les_r[i] = rui_r[i + 1] - r * (i + 1);
	reverse(all(a));
	vll max_l(n + 1); rep(i, n) max_l[i + 1] = max(max_l[i], les_l[i]);
	reverse(all(max_l)); max_l.pop_back(); reverse(all(max_l));
	vll max_r(n + 1); rep(i, n) max_r[i + 1] = max(max_r[i], les_r[i]);
	reverse(all(max_r)); max_r.pop_back();
	ll sum = accumulate(all(a), 0ll);
	ll ans = sum; // x = y = 0
	rep(i, n) chmin(ans, sum - max_l[i]); // x != 0, y = 0
	rep(i, n) chmin(ans, sum - max_r[i]); // x = 0, y != 0
	rep(i, n - 1) chmin(ans, sum - (max_l[i] + max_r[i + 1])); // x != 0, y != 0
	cout << ans << endl;
}