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
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i) + 1; cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n; cin >> n;
	vvll a(n, vll(n)), bad(n, vll(n));
	rep(i, n) rep(j, n) cin >> a[i][j];
	ll m; cin >> m;
	rep(i, m) {
		ll x, y; cin >> x >> y; x--; y--;
		bad[x][y] = bad[y][x] = true;
	}
	vll state(n); iota(all(state), 0);
	ll ans = INF;
	do{
		vll sta(n);
		rep(i, n) sta[state[i]] = i;
		ll cnt = 0;
		rep(i, n) cnt += a[i][state[i]]; //i人目がstate[i]の駅を担当
		ll flag = true;
		rep(i, n - 1) if(bad[sta[i]][sta[i + 1]]) flag = false;
		if(flag) chmin(ans, cnt);
	}while(next_permutation(all(state)));
	if(ans == INF) cout << -1 << endl;
	else cout << ans << endl;
}