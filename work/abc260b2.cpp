#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n, x, y, z; cin >> n >> x >> y >> z;
	vll a(n), b(n);
	rep(i, n) cin >> a[i]; rep(i, n) cin >> b[i];
	vll ans, done(n);
	rep(i, x) {
		ll cur = -1, p = -1;
		rep(j, n) {
			if(a[j] > p && !done[j]) cur = j, p = a[j];
		}
		ans.push_back(cur);
		done[cur] = true;
	}
	rep(i, y) {
		ll cur = -1, p = -1;
		rep(j, n) {
			if(b[j] > p && !done[j]) cur = j, p = b[j];
		}
		ans.push_back(cur);
		done[cur] = true;
	}
	rep(i, z) {
		ll cur = -1, p = -1;
		rep(j, n) {
			if(a[j] + b[j] > p && !done[j]) cur = j, p = a[j] + b[j];
		}
		ans.push_back(cur);
		done[cur] = true;
	}
	sort(all(ans));
	for(auto au : ans) cout << au + 1 << endl;
}