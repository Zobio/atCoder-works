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
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;}
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll h, w; cin >> h >> w;
	vvll a(h, vll(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	vvll ans;
	rep(i, h) rep(j, w - 1) if(a[i][j] & 1) { //各行についてマスに置かれているコインが奇数だったら右に1個ずらす
		ans.push_back({i + 1, j + 1, i + 1, j + 2});
		a[i][j]--; a[i][j + 1]++;
	}
	rep(i, h - 1) if(a[i].back() & 1) { //1番右の列についてマスに置かれているコインが奇数だったら下に1個ずらす
		ans.push_back({i + 1, w, i + 2, w});
		a[i].back()--; a[i + 1].back()++;
	}
	cout << ans.size() << endl;
	for(auto au : ans) {rep(i, au.size()) cout << au[i] << (i == au.size() - 1 ? "" : " "); cout << endl;}
}