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
	ll n; cin >> n;
	vll a(n); rep(i, n) cin >> a[i];
	vll b(200010); //仮想配列
	rep(i, n) b[a[i]]++;
	ll ans = 0;
	reps(i, 200000) for(ll j = i * (i - 1); j <= 200000; j += i) {
		ll p = i, q = j / i, r = j; //pq = r
		if(p == q && q == r) ans += b[i] * (b[i] - 1) * (b[i] - 2);
		else if(p == q) ans += b[p] * (b[p] - 1) * b[r];
		else if(q == r) ans += b[p] * b[q] * (b[q] - 1) * 2;
		else if(p == r) ans += b[p] * b[q] * (b[p] - 1) * 2;
		else ans += b[p] * b[q] * b[r] * 2;
	}
	cout << ans << endl;
}