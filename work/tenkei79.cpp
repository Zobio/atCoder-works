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
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll h, w; cin >> h >> w;
	vvll a(h, vll(w)); vvll b(h, vll(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	rep(i, h) rep(j, w) cin >> b[i][j];
	rep(i, h) rep(j, w) {
		b[i][j] -= a[i][j];
	}
	ll sum = 0;
	rep(i, h - 1) rep(j, w - 1) {
		ll ch = b[i][j];
		b[i][j] -= ch; b[i + 1][j] -= ch; b[i][j + 1] -= ch; b[i + 1][j + 1] -= ch;
		sum += abs(ch);
	}
	rep(i, h) if(b[i][w - 1] != 0) {cout << "No" << endl; return 0;}
	rep(i, w) if(b[h - 1][i] != 0) {cout << "No" << endl; return 0;}
	cout << "Yes" << endl << sum << endl; return 0;
}