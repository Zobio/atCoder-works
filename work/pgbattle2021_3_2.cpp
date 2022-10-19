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
	ll n, s; cin >> n >> s;
	vll d(n); rep(i, n) cin >> d[i], d[i]--;
	vll min_num(9), max_num(9);
	min_num.front() = 1, max_num.front() = 9;
	rep(i, 8) min_num[i + 1] = min_num[i] * 10;
	rep(i, 8) max_num[i + 1] = max_num[i] * 10 + 9;
	ll min_sum = 0, max_sum = 0;
	rep(i, n) min_sum += min_num[d[i]], max_sum += max_num[d[i]];
	if(!(min_sum <= s && s <= max_sum)) {cout << -1 << endl; return 0;}
	ll need = s - min_sum;
	vll plus(n); //{minus, pointer}
	vpll perm(n); rep(i, n) perm[i] = {max_num[d[i]] - min_num[d[i]], i};
	sort(rall(perm));
	rep(i, n) {
		if(need == 0) break;
		ll ch = perm[i].first, po = perm[i].second;
		ll mi = min(ch, need);
		need -= mi;
		plus[po] = mi;
	}
	rep(i, n) cout << min_num[d[i]] + plus[i] << " "; cout << endl;
}