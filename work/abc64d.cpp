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
	ll n; cin >> n;
	string s; cin >> s;
	vpll a;
	bool flag = true; //今は')'である
	rep(i, n) {
		if(s[i] == '(' && flag) a.push_back({0, 0}), flag = false;
		else if(a.empty()) a.push_back({0, 0});
		flag |= s[i] == ')';
		(flag ? a.back().second : a.back().first)++;
	}
	ll len = a.size();
	vll m(len); //'('と')'の対応
	rep(i, len) m[i] = len - 1 - i;
	vll fix(len);
	rep(i, len / 2) if(a[i].first > a[i].second) fix[m[i]] += a[i].first - a[i].second;
	for(ll i = len - 1; i > len / 2; i--) if(a[i].second > a[i].first) fix[m[i]] += a[i].second - a[i].first;
	rep(i, len) {
		if(fix[i]) cout << (i < len / 2 ? '(' : ')');
		if(!fix[m[i]]) {
			rep(j, a[i].first) cout << '(';
			rep(j, a[i].second) cout << ')';
		}else{
			ll ma = min(a[i].first, a[i].second);
			rep(j, ma) cout << '(';
			rep(j, ma) cout << ')';
		}
	}
	cout << endl;
}