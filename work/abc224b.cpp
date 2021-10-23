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
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll h,w; cin >> h >> w;
	vvll a(h, vll(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	rep(i, h) for(ll ii = i + 1; ii < h; ii++) {
		rep(j, w) for(ll jj = j + 1; jj < w; jj++) {
			if(a[i][j] + a[ii][jj] > a[i][jj] + a[ii][j]) {
				cout << "No" << endl; return 0;
			}
		}
	}
	cout << "Yes" << endl;
}