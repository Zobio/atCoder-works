#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (int i = 0; i < n; i++)
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
	int n; cin >> n;
	vector<short> a(n), b(n), d(n); rep(i, n) cin >> a[i] >> b[i] >> d[i];
	vector<short> ra(n), rb(n); rep(i, n) ra[i] = a[i] + b[i], rb[i] = a[i] - b[i]; //45度回転
	rep(i, n) rb[i] += 3000;
	short sa = *max_element(all(ra)) + 10, sb = *max_element(all(rb)) + 10;
	vector<vector<short>> cor(sa + 1, vector<short>(sb + 1)); rep(i, n) cor[ra[i]][rb[i]]++;
	vector<vector<int>> rui(sa + 2, vector<int>(sb + 2));
	rep(i, sa) rep(j, sb) {
		rui[i + 1][j + 1] = rui[i + 1][j] + rui[i][j + 1] - rui[i][j] + cor[i][j];
	}
	rep(i, n) {
		short ma1 = min(sa - 1, ra[i] + d[i]), ma2 = min(sb - 1, rb[i] + d[i]), mi1 = max(0, ra[i] - d[i]), mi2 = max(0, rb[i] - d[i]);
		cout << rui[ma1 + 1][ma2 + 1] - rui[ma1 + 1][mi2] - rui[mi1][ma2 + 1] + rui[mi1][mi2] << endl;
	}
}