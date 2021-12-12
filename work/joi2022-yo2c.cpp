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
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() { //bit全探索(部分点)
	ll h, w; cin >> h >> w;
	ll ans = 0, sum = 0;
	vvll a(h, vll(w)); rep(i, h) rep(j, w) cin >> a[i][j], sum += a[i][j];
	for(ll tate = 0; tate < (1ll << (h - 1)); tate++) {
		for(ll yoko = 0; yoko < (1ll << (w - 1)); yoko++) {
			vll border1, border2; bool flag = true;
			border1.push_back(0); border2.push_back(0);
			rep(i, h) if(tate & (1ll << i)) border1.push_back(i + 1); //borderが0だったら[0, 1]の間に国境線
			rep(i, w) if(yoko & (1ll << i)) border2.push_back(i + 1);
			border1.push_back(h); border2.push_back(w); sort(all(border1)); sort(all(border2));
			//arrcout(border1); arrcout(border2);
			rep(b1, border1.size() - 1) rep(b2, border2.size() - 1) {
				ll cnt = 0;
				for (ll gr1 = border1.at(b1); gr1 < border1.at(b1 + 1); gr1++) {
					for (ll gr2 = border2.at(b2); gr2 < border2.at(b2 + 1); gr2++) {
						cnt += a.at(gr1).at(gr2);
					}
				}
				//cout << cnt << " : " << (sum / (border1.size() + border2.size() - 4+1)) << endl;
				if(cnt != sum / ((border1.size() - 2 + 1) * (border2.size() - 2 + 1)/*端っこの分-2*/)) flag = false;
			}
			if(flag && (border1.size() != 2 || border2.size() != 2)) {
				ans++;// cout << "ANS" << endl;
			}
		}
	}
	cout << ans << endl;
}