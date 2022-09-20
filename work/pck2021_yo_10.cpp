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
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	setcout(15);
	ll hash = 21;

	ll n, m, k;
	cin >> n >> m >> k; //n角形、m枠
	pll st, en;
	cin >> st.first >> st.second >> en.first >> en.second;
	st.first--; en.first--;
	ld angle = 2 * PI / n;
	vector<vector<pair<ld, ld>>> cor(m, vector<pair<ld, ld>>(n)); //座標
	vector<vector<pair<ll, ld>>> g(m * hash);	//座標はハッシュ化して入れる 商がm, 余剰がn
	vector<vector<vector<ld>>> dist(m, vector<vector<ld>>(n, vector<ld>(k + 1, 100010))); //状態(i, j, k)での距離を保持
	rep(i, m) rep(j, n) {
		cor[i][j] = {polar<ld>(i + 1, angle * j).real(), polar<ld>(i + 1, angle * j).imag()};
	}
	rep(i, n) rep(j, m - 1) { //隣の枠 距離1
		ll p = j * hash + i, q = (j + 1) * hash + i;
		g[p].push_back({q, 1});
		g[q].push_back({p, 1});
	}

	rep(i, m) rep(j, n) { //同じ枠での距離
		ll p = i * hash + j, q = i * hash + ((j + 1) % n);
		pair<ld, ld> cp = cor[i][j], cq = cor[i][(j + 1) % n];
		ld di = sqrtl((cp.first - cq.first) * (cp.first - cq.first) + (cp.second - cq.second) * (cp.second - cq.second));
		g[p].push_back({q, di});
		g[q].push_back({p, di});
	}

	rep(i, n) for(ll j = 2; j < n - 1; j++) { //中心を通るクモの巣
		ll p = 0 * hash + i, q = 0 * hash + ((i + j) % n);
		pair<ld, ld> cp = cor[0][i], cq = cor[0][(i + j) % n];
		ld di = sqrtl((cp.first - cq.first) * (cp.first - cq.first) + (cp.second - cq.second) * (cp.second - cq.second));
		g[p].push_back({q, di});
	}

	rep(i, m - 1) rep(j, n) {
		ll p = i * hash + j, q = (i + 1) * hash + ((j + 1) % n), r = (i + 1) * hash + ((j - 1 + n) % n);
		pair<ld, ld> cp = cor[i][j], cq = cor[i + 1][(j + 1) % n];
		ld di = sqrtl((cp.first - cq.first) * (cp.first - cq.first) + (cp.second - cq.second) * (cp.second - cq.second));
		g[p].push_back({q, di}); g[p].push_back({r, di});
		g[q].push_back({p, di}); g[r].push_back({p, di});
	}

	//start Dijkstra's algorithm
	rep(i, k + 1) dist[st.first][st.second][i] = 0;
	//(cost, i, j, k)
	priority_queue<tuple<ld, ll, ll, ll>, vector<tuple<ld, ll, ll, ll>>, greater<tuple<ld, ll, ll, ll>>> que;
	 que.push({0, st.first, st.second, 0});

	while(!que.empty()) {
		tuple<ld, ll, ll, ll> p = que.top(); que.pop();
		auto [cost, i, j, used] = p;
		if(dist[i][j][used] < cost) continue;
		rep(nxt, g[i * hash + j].size()) {
			ll nxt_i = g[i * hash + j][nxt].first / hash, nxt_j = g[i * hash + j][nxt].first % hash;
			bool flag = false; //flagが立てば新たな線分
			flag |= nxt_i == i && abs(min((nxt_j - j + n) % n, n - (nxt_j - j + n) % n)) == 1;
			flag |= nxt_j == j && abs(min((nxt_i - i + m) % m, m - (nxt_i - i + m) % m)) == 1;
			if(used + !flag > k) continue;
			if(chmin(dist[nxt_i][nxt_j][used + !flag], dist[i][j][used] + g[i * hash + j][nxt].second)) {
				que.push({dist[nxt_i][nxt_j][used + !flag], nxt_i, nxt_j, used + !flag});
			}
		}
	}

	cout << *min_element(all(dist[en.first][en.second])) << endl;
}