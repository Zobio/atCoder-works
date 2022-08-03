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
	ll n, m; cin >> n >> m;
	vll a(n); rep(i, n) cin >> a[i];
	vll b(m); rep(i, m) cin >> b[i];
	ll sa = accumulate(all(a), 0ll), sb = accumulate(all(b), 0ll);
	if(sa == 0 && sb > 0) {cout << -1 << endl; return 0;} //aが全部0
	if(sa == n && sb < m) {cout << -1 << endl; return 0;} //aが全部1
	if(sa == 0 || sa == n) {cout << m << endl; return 0;}
	vvll p(2); rep(i, n) p[a[i]].push_back(i); //バケット
	if(sb == 0 || sb == m) {
		ll mi = INF;
		for(auto au : p[b.front()]) chmin(mi, min(au, n - au));
		cout << mi + m << endl; return 0;
	}else{
		ll ans = 0;
		ll mi = INF;
		for(auto au : p[b.front()]) {
			if(a[(au + 1) % n] != b.front() || a[(au - 1 + n) % n] != b.front()) chmin(mi, min(au, n - au));
		}
		ans += mi;
		ans += m;
		rep(i, m - 1) ans += b[i + 1] != b[i];
		cout << ans << endl;
	}
}