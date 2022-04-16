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

int main() {
	ll n, k; cin >> n >> k;
	if(k == 1) {cout << "Infinity" << endl; return 0;}
	vector<pll> c(n);
	rep(i, n) cin >> c[i].first >> c[i].second;
	vector<set<ll>> st(n * 310);
	ll cnt = 0;
	map<pair<pll, ll>, ll> m; //ハッシュ化用
	rep(i, n) for(ll j = i + 1; j < n; j++) {
		ll dx = c[j].first - c[i].first, dy = c[j].second - c[i].second;
		if(dx < 0) dx *= -1, dy *= -1; //dx, dyを一意に
		if(dx == 0 && dy < 0) dy *= -1;
		ll gc = __gcd(abs(dx), abs(dy));
		dx /= gc; dy /= gc;
		ll seppen;
		if(dx == 0) seppen = c[i].first; //x切片は一意
		else if(dy == 0) seppen = c[i].second; //y切片は一意
		else{
			ll p = -c[i].second * dx / dy;
			seppen = c[i].first + p; //x切片
		}
		if(m.find({{dx, dy}, seppen}) == m.end()) m[{{dx, dy}, seppen}] = cnt, cnt++;
		st[m[{{dx, dy}, seppen}]].insert(i);
		st[m[{{dx, dy}, seppen}]].insert(j);
	}
	ll ans = 0;
	for(auto au : st) {
		ans += au.size() >= k;
	}
	cout << ans << endl;
}