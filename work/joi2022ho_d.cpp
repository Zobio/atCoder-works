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
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

vvll g;

int main() {
	ll n, k, m; cin >> n >> k >> m; //n:駅 k:許容される駅数 m:列車の数
	vpll tr(m); rep(i, m) cin >> tr[i].first >> tr[i].second, tr[i].first--, tr[i].second--;
	ll q; cin >> q; //計画数
	vpll p(q); rep(i, q) cin >> p[i].first >> p[i].second, p[i].first--, p[i].second--;
	g.resize(n);
	rep(i, m) { //O(NM)
		ll from = tr[i].first, to = tr[i].second;
		if(from < to) for(ll j = from; j <= min(from + k - 1, to - 1); j++) { //始点
			for(ll k = j + 1; k <= to; k++) g[j].push_back(k);
		}
		else for(ll j = from; j >= max(from - k + 1, to + 1); j--) { //始点
			for(ll k = j - 1; k >= to; k--) g[j].push_back(k);
		}
	}
	vvll dis(n, vll(n)); //dis[i][j]:iからjに行くのに必要な電車の最小数
	rep(i, n) {
		vll tmp(n, INF); tmp[i] = 0;
		queue<ll> que; que.push(i);
		while(!que.empty()) { //BFS
			ll v = que.front(); que.pop();
			for (auto nv : g[v]) {
				if (tmp[nv] == INF) {
					tmp[nv] = tmp[v] + 1;
					que.push(nv);
				}
			}
		}
		dis[i] = tmp;
	}
	rep(i, q) { //O(NMQ)?
		ll st = p[i].first, en = p[i].second;
		cout << (dis[st][en] != INF ? dis[st][en] : -1) << endl;
	}
}