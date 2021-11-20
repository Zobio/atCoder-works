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
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n, m; cin >> n >> m;
	vvll b(n, vll(m));
	rep(i, n) rep(j, m) cin >> b[i][j];
	rep(i, n) rep(j, m - 1) {
		if(b[i][j + 1] - b[i][j] != 1) {cout << "No" << endl; return 0;}
	}
	rep(i, n - 1) rep(j, m) {
		if(b[i + 1][j] - b[i][j] != 7) {cout << "No" << endl; return 0;}
	}
	rep(i, m - 1) {
		if((b[0][i + 1] - 1) / 7ll != (b[0][i] - 1) / 7ll) {cout << "No" << endl; return 0;}
	}
	cout << "Yes" << endl;
}