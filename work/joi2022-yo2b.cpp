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
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

vvll g;

queue<pair<ll, ll>> q;
vvll d(1010, vll(1010, INF));
vll fx = {0, -1, 0, 1, 0}, fy = {0, 0, 1, 0, -1};

int main() {//BFS
	ll h, w; cin >> h >> w;
	g.resize(h, vll(w));
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	q.push({0, 0}); d[0][0] = 0;
	while(!q.empty()) {
		//cout << d[h - 1][w - 1] << endl;
		pair<ll, ll> xy = q.front(); q.pop();
		ll x = xy.first, y = xy.second;
		//cout << x << " " << y << endl;
		reps(i, 4) {
			ll tx = x + fx[i], ty = y + fy[i];
			if(tx >= 0 && tx < h && ty >= 0 && ty < w) {
				if(s[x][y] != s[tx][ty] && d[tx][ty] == INF) {
					d[tx][ty] = d[x][y] + 1;
					q.push({tx, ty});
				}
			}
		}
	}
	if(d[h - 1][w - 1] == INF) cout << -1 << endl;
	else cout << d[h - 1][w - 1] << endl;
}