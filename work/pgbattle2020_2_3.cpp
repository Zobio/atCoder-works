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
#define MOD 1000000007LL
#define mint modint1000000007
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n, m, d; cin >> n >> m >> d;
	vll a(m); rep(i, m) cin >> a[i], a[i]--;
	sort(all(a));
	map<ll, deque<mint>> dc;
	rep(i, m) dc[a[i] % d].push_back((a[i] - a[i] % d) / d);
	mint g1 = (d - n % d), g2 = n % d; //sizeがn/dのグループ、sizeがn/d+1のグループの個数
	for(auto au : dc) {
		if(au.first < n % d) g2--;
		else g1--;
	}
	mint ans = 0;
	//壊れているベルが存在しない等差数列の処理
	ans += g1 * (n / d) * (n / d + 1) / 2;
	ans += g2 * (n / d + 1) * (n / d + 1 + 1) / 2;
	//壊れているベルが存在する等差数列の処理
	for(auto& au : dc) au.second.push_front(0), au.second.push_back(au.first < n % d ? n / d + 1 - 1 : n / d - 1); //0-indexed
	for(auto au : dc) rep(i, au.second.size() - 1) {
		mint k = au.second.at(i + 1) - au.second.at(i);
		k -= 0 < i && i < au.second.size() - 2;
		ans += k * (k + 1) / 2;
	}
	cout << ans.val() << endl;
}