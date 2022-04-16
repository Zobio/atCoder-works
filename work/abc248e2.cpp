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
	vll x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	if(k == 1) {cout << "Infinity" << endl; return 0;}
	ll ans = 0;
	rep(i, n) for(ll j = i + 1; j < n; j++) {
		bool flag = false;
		rep(k, j) {
			if(k == i) continue;
			if((x[j] - x[i]) * (y[k] - y[j]) == (x[k] - x[j]) * (y[j] - y[i])) flag = true;
		}
		if(flag) continue; //jよりも前に直線上にある点が存在しているという事は、その直線上の点は既にカウントされている
		ll cnt = 2;
		for(ll k = j + 1; k < n; k++) {
			if ((x[j] - x[i]) * (y[k] - y[j]) == (x[k] - x[j]) * (y[j] - y[i])) cnt++;
		}
		ans += cnt >= k;
	}
	cout << ans << endl;
}