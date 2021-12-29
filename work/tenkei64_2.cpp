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

int main() {
	ll n, q; cin >> n >> q;
	vll a(n); rep(i, n) cin >> a[i];
	vll l(q), r(q), v(q);
	rep(i, q) cin >> l[i] >> r[i] >> v[i], l[i]--, r[i]--;
	vll b(n - 1); //aの階差数列
	rep(i, n - 1) b[i] = a[i + 1] - a[i];
	ll ans = 0; rep(i, n - 1) ans += abs(b[i]);
	rep(i, q) {
		ll before = (l[i] > 0 ? abs(b[l[i] - 1]) : 0) + (r[i] < n - 1 ? abs(b[r[i]]) : 0);
		if(l[i] > 0) b[l[i] - 1] += v[i];
		if(r[i] < n - 1) b[r[i]] -= v[i];
		ll after = (l[i] > 0 ? abs(b[l[i] - 1]) : 0) + (r[i] < n - 1 ? abs(b[r[i]]) : 0);
		ans += after - before;
		cout << ans << endl;
	} 
}