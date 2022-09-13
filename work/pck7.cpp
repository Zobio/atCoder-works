#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define INF (1ll << 60)
#define all(a) (a).begin(), (a).end()

template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T& a, const T& b) {if (b < a) {a = b; return 1;} return 0;}

int main() {
	//pqつかって残りの家管理
	//徴税官の{今いる家、徴税額}を管理
	ll n, m; cin >> n >> m;
	vll t(m), h(m); rep(i, m) cin >> t[i] >> h[i], h[i]--;
	vll done(n); rep(i, m) done[h[i]] = true;
	priority_queue<ll, vll, greater<ll>> house; rep(i, n) if(!done[i])house.push(i);
	priority_queue<ll, vpll, greater<pll>> p; rep(i, m) p.push({h[i], t[i]});
	ll ans = accumulate(all(t), 0ll); //最初の所は徴収し終わっているとする
	while(!house.empty()) {
		ll cur = house.top(); house.pop();
		pll chozei = p.top(); p.pop();
		if(chozei.first > cur) {
			p.push(chozei); continue;
		}
		ans += chozei.second;
		chozei.first = cur;
		p.push(chozei);
	}
	cout << ans << endl;
}