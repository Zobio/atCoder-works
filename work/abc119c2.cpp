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
#define dll deque<long long>
#define ddll deque<dque<long long>>
#define dddll deque<deque<deque<long long>>>
#define ddddll deque<deque<deque<deque<long long>>>>
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

ll n;
vll a(3);
vll l;

int main() {
	//それぞれのlが、a,b,cに寄与するのか、寄与しないのかの4通りと考える。
	//伸ばしたり縮めたりする作業はmergeしたあと1回するだけでいい(途中でやる必要はない)
	cin >> n;
	rep(i, 3) cin >> a[i];
	l.resize(n); rep(i, n) cin >> l[i];
	sort(all(l));
	ll ans = INF;
	rep(bits, 1LL << n * 2){
		vll type(n); //{寄与しない、a_1, a_2, a_3}
		rep(i, n) type[i] = bits >> i * 2 & 3;
		vvll b(3);
		rep(i, n) if(type[i]) b[type[i] - 1].push_back(l[i]);
		ll cost = 0;
		bool flag = true;
		rep(i, 3) {
			flag &= b[i].size() >= 1;
			cost += 10 * (b[i].size() - 1) + abs(accumulate(all(b[i]), 0ll) - a[i]);
		}
		if(!flag) continue;
		chmin(ans, cost);
	}
	cout << ans << endl;
}