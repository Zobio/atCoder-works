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
#define reep(i, a, b) for(long long i = a; i < b; i++)
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
#define YESS {printf("Yes\n"); return 0;}
#define NOO {printf("No\n"); return 0;}
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define mint modint998244353
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	//半分全列挙
	ull n, k, p; cin >> n >> k >> p;
	deque<ll> a(n); rep(i, n) cin >> a[i];
	sort(all(a));
	vll h1, h2;
	rep(i, n / 2) h1.push_back(a.front()), a.pop_front();
	while(a.size()) h2.push_back(a.front()), a.pop_front();
	vvll sum1(k + 1), sum2(k + 1);
	rep(bits, 1 << h1.size()) {
		ll cur = 0, cnt = 0;
		rep(i, h1.size()) if(1ll << i & bits) cur += h1[i], cnt++;
		if(cur <= p && cnt <= k) sum1[cnt].push_back(cur);
	}
	rep(bits, 1 << h2.size()) {
		ll cur = 0, cnt = 0;
		rep(i, h2.size()) if(1ll << i & bits) cur += h2[i], cnt++;
		if(cur <= p && cnt <= k) sum2[cnt].push_back(cur);
	}
	rep(i, k + 1) sort(all(sum1[i])), sort(all(sum2[i]));
	ll ans = 0;
	rep(i, k + 1) for(auto au : sum1[i]) {
		ans += upper_bound(all(sum2[k - i]), p - au) - sum2[k - i].begin();
	}
	cout << ans << endl;
}