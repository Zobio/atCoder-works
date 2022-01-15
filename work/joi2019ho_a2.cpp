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
	ll h, w; cin >> h >> w;vector<string> s(h); rep(i, h) cin >> s[i];
	vvll rui_O(h + 1, vll(w + 1)), rui_I(h + 1, vll(w + 1)); //「行」ごとの'O'の数、「列」ごとの'I'の数 の累積和
	rep(i, h) rep(j, w) rui_O[i][j + 1] += rui_O[i][j] + (s[i][j] == 'O');
	rep(i, w) rep(j, h) rui_I[j][i + 1] += rui_I[j][i] + (s[j][i] == 'I');
	ll ans = 0;
	rep(i, h+1) {rep(j, w+1) cout << rui_O[i][j]; cout << endl;}cout << endl;
	rep(i, h+1) {rep(j, w+1) cout << rui_I[i][j]; cout << endl;}
	rep(i, h) rep(j, w) if(s[i][j] == 'J') ans += (rui_O[i][w] - rui_O[i][j]) * (rui_I[j][h] - rui_I[j][i]);
	cout << ans << endl;
}