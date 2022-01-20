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

template<typename V>
void shrink_coordinates(V& a) {
	/*
	座標圧縮を行う関数
	(例)
	{6, 9, 9, 2, 100} -->  {1, 2, 2, 0, 3}
	*/
	V b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	V res(a.size());
	for(long long i = 0; i < a.size(); i++) {
		res.at(i) = lower_bound(b.begin(), b.end(), a.at(i)) - b.begin();
	}
	a = res;
}

vvll imos;
vll dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1}; //4方位ベクトル
ll max_h = 0, max_w = 0; //縦、横の(座圧後の)最大値

void dfs(ll y, ll x) {
	imos[y][x] = 1;
	rep(i, 4) {
		ll nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < max_w && ny >= 0 && ny < max_h && !imos[ny][nx]) dfs(ny, nx);
	}
	return;
}

int main() { //座圧→2次元imos→DFS
	ll h, w, n; cin >> w >> h >> n;
	vector<pair<pair<ll, ll>, pair<ll, ll>>> xy; //テープの座標を格納
	vll cor; //全座標を格納(座圧用)
	rep(i, n) {
		ll a, b, c, d; cin >> a >> b >> c >> d; a--; b--; c--; d--;
		xy.push_back({{a, b}, {c, d}});
		cor.push_back(a); cor.push_back(b); cor.push_back(c); cor.push_back(d);
	}
	vll old = cor; //座圧前の配列を保存
	shrink_coordinates(cor); //座圧実行
	map<ll, ll> ch; //<座圧前、座圧後>の仮想配列
	rep(i, cor.size()) ch[old[i]] = cor[i];
	rep(i, n) { //変換
		xy.at(i).first.first = ch.at(xy[i].first.first);
		xy.at(i).first.second = ch.at(xy[i].first.second);
		xy.at(i).second.first = ch.at(xy[i].second.first);
		xy.at(i).second.second = ch.at(xy[i].second.second);
		chmax(max_h, xy[i].first.first);
		chmax(max_h, xy[i].second.first);
		chmax(max_w, xy[i].first.second);
		chmax(max_w, xy[i].second.second);
	} //ここまで座圧
	imos.resize(max_h + 1, vll(max_w + 1));
	rep(i, n) {
		ll a = xy[i].first.first, b = xy[i].first.second, c = xy[i].second.first, d = xy[i].second.second;
		imos[a][b]++; imos[a][d]--; imos[c][b]--; imos[c][d]++;
	}
	rep(i, max_h) rep(j, max_w - 1) {
		imos[i][j + 1] += imos[i][j];
	}
	rep(i, max_w) rep(j, max_h - 1) {
		imos[j + 1][i] += imos[j][i];
	} //ここまで2次元imos
	ll ans = 0;
	rep(i, max_h) rep(j, max_w) {
		if(!imos[i][j]) ans++, dfs(i, j);
	}
	cout << ans << endl;
}