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

template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T& a, const T& b) {if (b < a) {a = b; return 1;} return 0;}

int main() {
	ll n; cin >> n; 
	vpll a(n); rep(i, n) cin >> a[i].first >> a[i].second;
	ll m; cin >> m;
	vll b(m); rep(i, m) cin >> b[i];
	vpll time(3, {INF, -INF}); //茹でなさすぎ、ちょうど、茹ですぎのmin,max
	rep(i, n) {
		ll type = a[i].second, s = a[i].first;
		chmin(time[type].first, s);
		chmax(time[type].second, s);
	}
	rep(i, m) {
		ll cur = b[i];
		if(cur <= time[0].second) cout << 0 << endl;
		else if(time[1].first <= cur && cur <= time[1].second) cout << 1 << endl;
		else if(time[2].first <= cur) cout << 2 << endl;
		else cout << -1 << endl;
	}
}