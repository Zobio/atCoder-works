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
	//にぶたん??
	ll n, m; cin >> n >> m;
	vll a(n); rep(i, n) cin >> a[i];
	deque<deque<ll>> h(n);
	rep(i, n) {
		ll delta = a[i] >= 0 ? 0 : (-a[i]) / (i + 1);
		ll cur = a[i] + delta * (i + 1);
		ll cnt = delta;
		if(cur < 0) cnt++, cur += (i + 1);
		while(cur < n && cnt <= m) h[cur].push_back(cnt), cur += (i + 1), cnt++;
	}
	rep(i, n) sort(all(h[i]));
	//h[i][j] : iになるのにj回かかった
	set<ll> notdone;
	rep(i, m) notdone.insert(i);
	vll ans(m, -1);
	rep(i, n) { //i行目
		vll tmp;
		for(auto au : notdone) {
			if(!binary_search(all(h[i]), au)) ans[au] = 0, tmp.push_back(au);
			else chmin(ans[au], i + 1)
		}
		for(auto t : tmp) notdone.erase(t);
	}
	rep(i, m) cout << ans[i] << endl;
}