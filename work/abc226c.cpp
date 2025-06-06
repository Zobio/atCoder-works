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
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll n;
vll t;
vvll g;
ll ans;
vector<bool> seen;

void dfs(ll v) {
	ans += t[v];
	seen[v] = true;
	fore(next_v, g[v]) {
		if(seen[next_v]) continue;
		dfs(next_v);
	}
}

int main() {
	cin >> n;
	t.resize(n); g.resize(n); seen.resize(n);
	rep(i, n) {
		cin >> t.at(i);
		ll k; cin >> k;
		rep(j, k) {ll tmp; cin >> tmp; tmp--; g.at(i).push_back(tmp);}
	}
	dfs(n - 1);
	cout << ans << endl;
}