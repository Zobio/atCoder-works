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
	ll n, d, k; cin >> n >> d >> k;
	vll l(d), r(d); rep(i, d) cin >> l[i] >> r[i];
	vll s(k), t(k); rep(i, k) cin >> s[i] >> t[i];
	vvll p(k, vll(d + 1)); //最適に行動したときの各民族の現在地
	rep(i, k) rep(j, d + 1) p[i][j] = s[i];
	rep(i, k) rep(j, d) {
		if(p[i][j] == t[i]) break; //already reached
		if(!(l[j] <= p[i][j] && p[i][j] <= r[j])) {p[i][j + 1] = p[i][j]; continue;} //cannnot move

		if(s[i] < t[i]) chmax(p[i][j + 1], min(r[j], t[i]));
		else chmin(p[i][j + 1], max(l[j], t[i]));
	}
	rep(i, k) reps(j, d) {
		if(p[i][j] == t[i]) {
			cout << j << endl; break;
		}
	}
}