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

vll dx = {-1, 0, 1}, dy = {-1, 0, 1};

int main() {
	ll h, w; cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	vvll done(h, vll(w)), ans(h, vll(w));
	rep(i, h) rep(j, w) {
		if(s[i][j] == '.') continue;
		bool flag = true;
		rep(p, 3) rep(q, 3) {
			ll ny = i + dy[p], nx = j + dx[q];
			if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if(s[ny][nx] == '.') flag = false;
		}
		if(flag) {
			ans[i][j] = true;
			rep(p, 3) rep(q, 3) {
				ll ny = i + dy[p], nx = j + dx[q];
				if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
				if(s[ny][nx] == '#') done[ny][nx] = true;
			}
		}
	}
	rep(i, h) rep(j, w) {
		if(s[i][j] == '#' && !done[i][j]) {cout << "impossible" << endl; return 0;}
	}
	cout << "possible" << endl;
	rep(i, h) {
		rep(j, w) cout << (ans[i][j] ? '#' : '.');
		cout << endl;
	}
}