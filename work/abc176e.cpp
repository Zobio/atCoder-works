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

int main() {
	ll h, w, m; cin >> h >> w >> m;
	vpll b(m); rep(i, m) cin >> b[i].first >> b[i].second, b[i].first--, b[i].second--;
	map<ll, ll> cnt_h, cnt_w;
	map<pll, ll> cnt_hw;
	rep(i, m) {
		cnt_h[b[i].first]++;
		cnt_w[b[i].second]++;
		cnt_hw[b[i]]++;
	}
	ll hmax = 0, wmax = 0;
	for(auto au : cnt_h) chmax(hmax, au.second);
	for(auto au : cnt_w) chmax(wmax, au.second);
	vll H, W;
	for(auto au : cnt_h) if(au.second == hmax) H.push_back(au.first);
	for(auto au : cnt_w) if(au.second == wmax) W.push_back(au.first);
	bool flag = false;
	for(auto ah : H) for(auto aw : W) if(!cnt_hw.count({ah, aw})) cout << hmax + wmax << endl, exit(0); //鳩ノ巣原理
	cout << hmax + wmax - 1 << endl;
}