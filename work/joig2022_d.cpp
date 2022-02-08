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

int main() {
	ll h, w, n; cin >> h >> w >> n;
	vpll cor(n); rep(i, n) cin >> cor[i].first >> cor[i].second, cor[i].first--, cor[i].second--;
	map<ll, vll> a1, a2, a3, a4; //順に右、下、左、上の二分探索用
	rep(i, n) {
		ll x = cor[i].second, y = cor[i].first;
		a1[y].push_back(x); //右
		a2[x].push_back(y); //下
		a3[y].push_back(-x); //左
		a4[x].push_back(-y); //上
	}
	vll delta = {-1, 0, 1}; //方向ベクトル(始点を調整)
	ll ans = 0;
	rep(i, n) {
		rep(j, 9) {
			ll cnt = 0;
			ll y = cor[i].first, x = cor[i].second;
			ll dy = delta[j / 3], dx = delta[j % 3];
			if(y + dy > h || x + dx > w || y + dy < 0 || x + dx < 0) continue;
			if(dy > 0) cnt += a4[x].size() - ((upper_bound(all(a4[x]), -(y - dy))) - a4[x].begin());
			if(dx > 0) cnt += a3[y].size() - ((upper_bound(all(a3[y]), -(x - dx))) - a3[y].begin());
			cnt += upper_bound(all(a2[x]), x + dx) - a2[x].begin();
			cnt += upper_bound(all(a1[y]), y + dy) - a1[y].begin();
			cout << i << " : " << y + dy  << " " << x + dx << " " << cnt + 1 << endl;
			chmax(ans, cnt + 1);
		}
	}
	cout << ans << endl;
}