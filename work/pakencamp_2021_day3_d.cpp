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
	ll n, t; cin >> n >> t;
	vpll a(n), b(n); rep(i, n) cin >> a[i].first >> a[i].second;
	ll ans = 0;
	rep(bits, 1 << n) {
		vll p, q;
		rep(i, n){
			if(bits & (1 << i)) p.push_back(a[i].first), q.push_back(a[i].second);
		}
		sort(all(p)); sort(all(q));
		ll c1 = 0, c2 = 0, n1 = 0, n2 = 0;
		for(auto au : p) {
			n1 += au;
			if(n1 > t) break;
			c1++;
		}
		for(auto au : q) {
			n2 += au;
			if(n2 > t) break;
			c2++;
		}
		chmax(ans, c1 - c2);
	}
	cout << ans << endl;
}