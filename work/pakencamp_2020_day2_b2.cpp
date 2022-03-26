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
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll h, w;
vector<string> c;

void solve1() {
	ll ans = 0;
	rep(i, w) ans += c[0][i] == 'S';
	cout << ans << endl;
}

void solve2() {
	vll rui1(w + 1), rui2(w + 1); //1行目の左からの'S'の累積和、2行目の右からの'S'の累積和
	rep(i, w) rui1[i + 1] = rui1[i] + (c[0][i] == 'S');
	rrep(i, w) rui2[i] = rui2[i + 1] + (c[1][i] == 'S');
	ll ans = INF;
	rep(i, w) {
		ll cnt = 0;
		cnt += rui1[i + 1] + (c[0][i] == 'S' ? -1 : 1); //1行目
		cnt += rui2[i];
		chmin(ans, cnt);
	}
	cout << ans << endl;
}

int main() { //80点解法(H=2)
	cin >> h >> w;
	c.resize(h);
	rep(i, h) cin >> c[i];
	if(h == 1) solve1();
	else solve2();
}