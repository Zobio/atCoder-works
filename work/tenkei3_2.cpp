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
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n; cin >> n;
	vvll g(n);
	rep(i, n - 1) {
		ll a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b); g[b].push_back(a);
	}
	vll dis(n, INF);
	queue<ll> q;
	q.push(0); dis[0] = 0;
	while(!q.empty()) {
		ll cur = q.front(); q.pop();
		for (auto to : g[cur]) {
			if (dis[to] == INF) {
				dis[to] = dis[cur] + 1;
				q.push(to);
			}
		}
	}
	ll maxn1 = -1, maxid1 = -1;
	rep(i, n) if(chmax(maxn1, dis[i])) maxid1 = i;
	fill(all(dis), INF);
	dis[maxid1] = 0; q.push(maxid1);
	while(!q.empty()) {
		ll cur = q.front(); q.pop();
		for (auto to : g[cur]) {
			if (dis[to] == INF) {
				dis[to] = dis[cur] + 1;
				q.push(to);
			}
		}
	}
	ll maxn2 = -1, maxid2 = -1;
	rep(i, n) if(chmax(maxn2, dis[i])) maxid2 = i;
	cout << maxn2 + 1 << endl;
}