#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n, m; cin >> n >> m;
	vvll g(n);
	rep(i, m) {
		ll a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
	}
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	vll cnt(n);
	rep(i, n) rep(j, g[i].size()) cnt[g[i][j]]++;
	rep(i, n) {
		if(cnt[i] == 0) pq.push(i);
	}
	vll ans;
	while(!pq.empty()) {
		ll now = pq.top(); pq.pop();
		ans.push_back(now + 1);
		for(auto a : g[now]) {
			cnt[a]--;
			if(cnt[a] == 0)pq.push(a);
		}
	}
	if(ans.size() < n) cout << -1 << endl;
	else arrcout(ans);
}