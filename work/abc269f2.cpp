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

mint sum_tousa(ll a, ll d, ll n) {
	mint aa = a, dd = d, nn = n;
	return nn * (2 * aa + (nn - 1) * dd) / 2;
}

int main() {
	ll n, m; cin >> n >> m;
	ll q; cin >> q;
	vector<mint> ans;
	rep(_, q) {
		ll a, b, c, d; cin >> a >> b >> c >> d;
		ll h = b - a + 1, w = d - c + 1;
		ll h1, w1, h2, w2; //col1の横の要素数、縦の要素数、col2の横の要素数、縦の要素数

		if(h & 1) h1 = h / 2 + 1;
		else h1 = h / 2;

		if(!(a + c & 1) && w & 1) w1 = w / 2 + 1;
		else w1 = w / 2;

		h2 = h / 2;

		if(!(a + 1 + c & 1) && w & 1) w2 = w / 2 + 1;
		else w2 = w / 2;

		mint col1 = 0, col2 = 0, cur = 0;

		col1 = sum_tousa((a - 1) * m + c + (a + c & 1), 2, w1);
		cur += sum_tousa(col1.val(), 2 * m * w1, h1);

		col2 = sum_tousa((a + 1 - 1) * m + c + (a + 1 + c & 1), 2, w2);
		cur += sum_tousa(col2.val(), 2 * m * w2, h2);

		ans.push_back(cur);
	}
	rep(i, q) cout << ans[i].val() << endl;
}