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
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll w, h, n; cin >> w >> h >> n;
	vector<pair<ll, ll>> sp(n);
	rep(i, n) cin >> sp[i].first >> sp[i].second;
	ll ans = 0;
	reps(i, n - 1) {
		ll dx = sp[i].first - sp[i - 1].first;
		ll dy = sp[i].second - sp[i - 1].second;
		if(dx * dy >= 0) {
			ans += max(abs(sp[i].first - sp[i - 1].first), abs(sp[i].second - sp[i - 1].second));
		}else{
			ans += abs(sp[i].first - sp[i - 1].first) + abs(sp[i].second - sp[i - 1].second);
		}
	}
	cout << ans << endl;
}