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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define mint modint998244353
#define INF (1LL << 60)
#define YESS {printf("Yes"); return 0;}
#define NOO {printf("No"); return 0;}
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	string s; cin >> s;
	if(s.front() == '1') NOO;
	map<ll, ll> mp;
	mp[1] = 3, mp[2] = 2, mp[3] = 4, mp[4] = 1, mp[5] = 3, mp[6] = 5, mp[7] = 0, mp[8] = 2, mp[9] = 4, mp[10] = 6;
	vvll a(7);
	rep(i, 10) a[mp[i + 1]].push_back(s[i] - '0');
	rep(i, 7) reep(j, i + 2, 7) {
		if(accumulate(all(a[i]), 0ll) == 0) continue;
		if(accumulate(all(a[j]), 0ll) == 0) continue;
		reep(k, i + 1, j) if(accumulate(all(a[k]), 0ll) == 0) YESS;
	}
	cout << "No" << endl;
}