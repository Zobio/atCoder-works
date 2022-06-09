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
	ll n; cin >> n;
	vll a(n); rep(i, n) cin >> a[i];
	vll b(n); rep(i, n) cin >> b[i];
	map<ll, ll> m; ll cnt = 0;
	rep(i, n) {
		if(m.find(a[i]) == m.end()) m[a[i]] = cnt, cnt++;
	}
	rep(i, n) {
		if(m.find(b[i]) == m.end()) m[b[i]] = cnt, cnt++;
	}
	vll aa(n); rep(i, n) aa[i] = m[a[i]]; //番号を振りなおす
	vll bb(n); rep(i, n) bb[i] = m[b[i]]; //番号を振りなおす
	set<ll> sa, sb; //aa, bbの集合
	vll siz_a(n), siz_b(n); //sa, sbの要素数
	rep(i, n) sa.insert(aa[i]), siz_a[i] = sa.size();
	rep(i, n) sb.insert(bb[i]), siz_b[i] = sb.size();
	vll ma(n + 1), mb(n + 1); //aa, bbの累積max
	rep(i, n) chmax(ma[i + 1], max(ma[i], aa[i]));
	rep(i, n) chmax(mb[i + 1], max(mb[i], bb[i]));
	ll q; cin >> q;
	rep(_, q) {
		ll x, y; cin >> x >> y; x--; y--;
		cout << (siz_a[x] == siz_b[y] && ma[x + 1] == mb[y + 1] ? "Yes" : "No") << endl;
	}
}