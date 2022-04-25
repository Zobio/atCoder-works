#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
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
#define INF (1LL << 60)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

set<ll> t;

bool check(string cur) {
	return count(all(cur), '3') && count(all(cur), '5') && count(all(cur), '7');
}

void dfs(string cur) {
	cout << cur << endl;
	t.insert(stoll(cur));
	ll flag = false;
	string pre = cur;
	rrep(i, cur.size()) {
		cur.replace(i, 1, "3");
		if(cur[i] != '3' && check(cur)) {dfs(cur); flag = true; break;}
		cur.replace(i, 1, "5");
		if(cur[i] != '5' && check(cur)) {dfs(cur); flag = true; break;}
		cur.replace(i, 1, "7");
		if(cur[i] != '7' && check(cur)) {dfs(cur); flag = true; break;}
		cur = pre;
	}
	if(!flag && cur.size() < 8) dfs("3" + cur);
}

int main() {
	ll n; cin >> n;
	dfs("357");
	vll p;
	for(auto au : t) p.push_back(au);
	cout << lower_bound(all(p), n) - p.begin() << endl;
}