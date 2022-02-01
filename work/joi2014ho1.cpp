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
vector<string> a, em(2);

int main() {
	cin >> h >> w;
	a.resize(h); rep(i, h) cin >> a[i];
	rep(i, 2) cin >> em[i];
	vvll defa_cnt(h, vll(w));
	ll defa = 0;
	rep(i, h-1) rep(j, w-1) {
		bool flag = true;
		rep(k, 2) rep(l, 2) {
			if(em[k][l] != a[i + k][j + l]) flag = false;
		}
		if(flag) {
			defa_cnt[i][j]++; defa_cnt[i][j + 1]++; defa_cnt[i + 1][j]++; defa_cnt[i + 1][j + 1]++;
			defa++;
		}
	}
	ll ans = defa; //文字を変えなかったときのans
	rep(i, h) rep(j, w) rep(k, 3) {
		ll state, pt = 0, pre = a[i][j];
		if(k == 0) state = 'J'; else if(k == 1) state = 'O'; else state = 'I';
		a[i][j] = state; //色変更
		pt -= defa_cnt[i][j];
		rep(delta, 4) {//紋章の「左上の」座標
			ll dx = ((delta >> 1) & 1 ? -1 : 0), dy = (delta & 1 ? -1 : 0);
			ll ny = i + dy, nx = j + dx;
			if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
			bool flag = true;
			rep(l, 2) rep(m, 2) {
				if(ny + l >= h || nx + m >= w) {flag = false; continue;} //端っこなので紋章を作る領域がない
				if(em[l][m] != a.at(ny + l).at(nx + m)) flag = false;
			}
			pt += flag;
		}
		if(pt > 0) chmax(ans, defa + pt);
		a[i][j] = pre; //色を戻す
	}
	cout << ans << endl;
}