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

vector<ll> enum_divisors(ll n) {
	vector<ll> res;
	ll pre = -1;
	while(n > 1) {
		if(n == pre) {res.push_back(n); break;}
		pre = n;
		for(ll i = 2; i * i <= n; i++) if(n % i == 0) {res.push_back(i), n /= i; break;}
	} 
	sort(all(res));
	return res;
}

int main() {
	ll n; cin >> n;
	ll ans = 0;
	reps(i, n) {
		vll div = enum_divisors(i);
		map<ll, ll> cnt;
		for(auto au : div) cnt[au]++;
		ll cur = 1ll;
		for(auto au : cnt) if(au.second & 1) cur *= au.first;
		ll l = 1, r = 200010;
		while(r - l > 1) {
			ll mid = (l + r) / 2;
			if(mid * mid  * cur <= n) l = mid;
			else r = mid;
		}
		ans += l;
	}
	cout << ans << endl;
}