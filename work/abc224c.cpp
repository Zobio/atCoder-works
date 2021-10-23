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
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n;cin >> n;
	vector<pair<ll, ll>> xy(n);
	rep(i, n) cin >> xy[i].first >> xy[i].second;
	sort(all(xy));
	ll ans = (n * (n - 1) * (n - 2)) / 6; 
	rep(a, n) for(ll b = a + 1; b < n; b++) for(ll c = b + 1; c < n; c++) {
		if((xy[b].first - xy[a].first) * xy[b].second + (xy[b].second - xy[a].second) * (xy[c].first - xy[b].first) == xy[c].second * (xy[b].first - xy[a].first)) ans--;
	}
	cout << ans << endl;
}