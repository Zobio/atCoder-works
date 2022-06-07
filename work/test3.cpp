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
	vvpll ans(n + 1);
	vll b(n + 1); iota(all(b), 0ll);
	for(ll i = 2; i * i <= n; i++) for(ll j = 1; i * j <= n; j++){ //O(NloglogN)
		ll cnt = 0;
		while(b[i * j] != 1 && b[i * j] % i == 0) cnt++, b[i * j] /= i;
		if(cnt > 0)ans[i * j].push_back({i, cnt});
	}
	reps(i, n) sort(all(ans[i]));
	reps(i, n) {
		if(b[i] != 1) ans[i].push_back({b[i], 1ll});
	}
	reps(i, n) {
		cout << i << " : ";
		for(auto au : ans[i]) cout << au.first << "^" << au.second << (au.first != ans[i].back().first ? " * " : "");
		cout << endl;
	}
}