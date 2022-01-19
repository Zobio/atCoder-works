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
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n; cin >> n;
    vvll imos(1010, vll(1010));
    rep(i, n) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        imos[a][b]++; imos[a][d]--; imos[c][b]--; imos[c][d]++;
    }
	for (int i = 0; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) imos[i][j] += imos[i][j - 1];
	}
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) imos[i][j] += imos[i - 1][j];
	}
	vll ans(n + 1); //仮想配列
	rep(i, 1001) rep(j, 1001) ans[imos[i][j]]++;
	reps(i, n) cout << ans[i] << endl;
}