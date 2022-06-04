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
	vll a(n), b(n);
	rep(i, n) cin >> a[i]; rep(i, n) cin >> b[i];
	vll sa(n), sb(n); //各集合のサイズを保存しておく配列
	set<ll> tmp1, tmp2;
	vll na, nb;
	rep(i, n) {
		if(tmp1.find(a[i]) != tmp1.end()) {
			tmp1.insert(a[i]);
			na.push_back(a[i]);
		}
		sa[i] = tmp1.size();
	}
	rep(i, n) {
		if(tmp2.find(a[i]) != tmp2.end()) {
			tmp2.insert(b[i]);
			nb.push_back(b[i]);
		}
		sb[i] = tmp2.size();
	}
	set<ll> s;
	vll ssiz;
	rep(i, )
	ll q; cin >> q;
	rep(_, q) {
		ll x, y; cin >> x >> y; x--; y--;
		if(sa[x] != sb[y]) continue;

	}
}