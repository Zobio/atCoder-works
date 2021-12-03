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
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

vvll key(10, vll(10));

int main() {
	ll m, r; cin >> m >> r;
	key[0][1] = 1; key[0][2] = 2; key[0][3] = 3; key[0][4] = 2; key[0][5] = 3; key[0][6] = 4;
	key[0][7] = 3; key[0][8] = 4; key[0][9] = 5;
	key[1][2] = 1; key[1][3] = 2; key[1][4] = 1; key[1][5] = 2; key[1][6] = 3; key[1][7] = 2;
	key[1][8] = 3; key[1][9] = 4;
	key[2][3] = 1; key[2][4] = 2; key[2][5] = 1; key[2][6] = 2; key[2][7] = 3; key[2][8] = 2;
	key[2][9] = 3;
	key[3][4] = 3; key[3][5] = 2; key[3][6] = 1; key[3][7] = 4; key[3][8] = 3; key[3][9] = 2;
	key[4][5] = 1; key[4][6] = 2; key[4][7] = 1; key[4][8] = 2; key[4][9] = 3;
	key[5][6] = 1; key[5][7] = 2; key[5][8] = 1; key[5][9] = 2;
	key[6][7] = 3; key[6][8] = 2; key[6][9] = 1;
	key[7][8] = 1; key[7][9] = 2;
	key[8][9] = 1;
	rep(i, 10) key[i][i] = 0;
	ll ans = INF;
	rep(_, 15000000ll) {
		string rs = to_string(r);
		ll cnt = key[0][rs[0] - '0'];
		rep(i, rs.size() - 1) {
			cnt += key[min(rs.at(i + 1) - '0', rs.at(i) - '0')][max(rs.at(i + 1) - '0', rs.at(i) - '0')];
		}
		cnt += rs.size();
		chmin(ans, cnt);
		r += m;
		if(r > 10000000000000000000ll) break;
	}
	cout << ans << endl;
}