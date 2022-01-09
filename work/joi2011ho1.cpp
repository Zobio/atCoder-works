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
#define pll pair<ll, ll>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n, m, k; cin >> n >> m >> k;
	vector<string> a(n); rep(i, n) cin >> a[i];
	vector<pair<pll, pll>> q(k);
	rep(i, k) {
		ll a, b, c, d; cin >> a >> b >> c >> d;
		q[i] = {{a, b}, {c, d}};
	}
	vvll rui_J(n + 1, vll(m + 1)); vvll rui_O(n + 1, vll(m + 1)); vvll rui_I(n + 1, vll(m + 1));
	rep(i, n) rep(j, m) { //2次元累積和
		rui_J[i + 1][j + 1] += rui_J[i + 1][j] + rui_J[i][j + 1] - rui_J[i][j] + (a[i][j] == 'J');
		rui_O[i + 1][j + 1] = rui_O[i + 1][j] + rui_O[i][j + 1] - rui_O[i][j] + (a[i][j] == 'O');
		rui_I[i + 1][j + 1] = rui_I[i + 1][j] + rui_I[i][j + 1] - rui_I[i][j] + (a[i][j] == 'I');
	}
	rep(i, k) {
		ll A = q[i].first.first, B = q[i].first.second, C = q[i].second.first, D = q[i].second.second;
		cout << rui_J[C][D] - rui_J[A-1][D] - rui_J[C][B-1] + rui_J[A-1][B-1] << " " << rui_O[C][D] - rui_O[A-1][D] - rui_O[C][B-1] + rui_O[A-1][B-1] << " " << rui_I[C][D] - rui_I[A-1][D] - rui_I[C][B-1] + rui_I[A-1][B-1] << endl;
	}
}