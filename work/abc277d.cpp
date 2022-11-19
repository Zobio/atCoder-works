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

struct grp{
	vll nums;
	ll sum;
};

int main() {
	ll n, m; cin >> n >> m;
	vll a(n); rep(i, n) cin >> a[i];
	vpll p(n); rep(i, n) p[i] = {a[i] % m, a[i]};
	sort(all(p));
	vector<grp> gs;
	rep(i, n) {
		if(gs.empty()) gs.push_back({{p[i].first}, p[i].second});
		else{
			ll diff = p[i].first - gs.back().nums.back();
			if(diff == 1) gs.back().nums.push_back(p[i].first), gs.back().sum += p[i].second;
			else if(diff == 0) gs.back().sum += p[i].second;
			else gs.push_back({{p[i].first}, p[i].second});
		}
	}
	ll minu = 0;
	for(auto au : gs) chmax(minu, au.sum);
	if(gs.front().nums.front() == 0 && gs.back().nums.back() == m - 1) chmax(minu, gs.front().sum + (gs.size() >= 2 ? gs.back().sum : 0));
	cout << accumulate(all(a), 0ll) - minu << endl;
}