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

struct UnionFind {
	long long groups;
	vector<long long> parents;

	UnionFind(long long n) {
		groups = n;
		parents = vector<long long>(n, -1);
	}

	long long find(long long x) {
		if (parents.at(x) < 0) {
			return x;
		}else{
			parents[x] = find(parents[x]);
			return parents[x];
		}
	}

	void unite(long long x, long long y) {
		x = find(x);
		y = find(y);

		// already united
		if (x == y)
			return;

		groups--;

		if (parents[x] > parents[y])
			swap(x, y);

		parents[x] += parents[y];
		parents[y] = x;
	}

	long long size(long long x) {
		return -parents[find(x)];
	}

	bool issame(long long x, long long y) {
		return find(x) == find(y);
	}

	vector<long long> roots() {
		vector<long long> ret;
		for (long long i = 0; i < parents.size(); i++)
			if (parents[i] < 0)
				ret.push_back(i);
		return ret;
	}

	long long group_count() {
		return groups;
	}
};

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

vector<vector<int>> imos;
vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1}; //4方位ベクトル
int max_h = 0, max_w = 0; //縦、横の(座圧後の)最大値

int main() { //座圧→2次元imos→UFで連結判定
	int h, w, n; cin >> w >> h >> n;
	vector<pair<pair<int, int>, pair<int, int>>> xy; //テープの座標を格納
	vector<int> cor_h; //全y座標を格納(座圧用)
	vector<int> cor_w; //全x座標を格納(座圧用)
	rep(i, n) {
		int a, b, c, d; cin >> a >> b >> c >> d; a--; b--; c--; d--;
		xy.push_back({{a, b}, {c, d}});
		cor_h.push_back(a); cor_w.push_back(b); cor_h.push_back(c); cor_w.push_back(d);
	}
	vector<int> old_h = cor_h, old_w = cor_w; //座圧前の配列を保存
	shrink_coordinates(cor_h); shrink_coordinates(cor_w); //座圧実行
	map<int, int> ch_h, ch_w; //<座圧前、座圧後>の仮想配列
	rep(i, cor_h.size()) ch_h[old_h[i]] = cor_h[i];
	rep(i, cor_w.size()) ch_w[old_w[i]] = cor_w[i];
	rep(i, n) { //変換
		xy[i].first.first = ch_h[xy[i].first.first];
		xy[i].first.second = ch_w[xy[i].first.second];
		xy[i].second.first = ch_h[xy[i].second.first];
		xy[i].second.second = ch_w[xy[i].second.second];
		chmax(max_h, xy[i].first.first);
		chmax(max_h, xy[i].second.first);
		chmax(max_w, xy[i].first.second);
		chmax(max_w, xy[i].second.second);
	} //ここまで座圧
	vector<int>().swap(old_h); vector<int>().swap(old_w);
	vector<int>().swap(cor_h); vector<int>().swap(cor_w);
	map<int, int>().swap(ch_h); map<int, int>().swap(ch_h); //swap()による強制的なメモリ解放(?)
	imos.resize(max_h + 1, vector<int>(max_w + 1));
	rep(i, n) {
		int a = xy[i].first.first, b = xy[i].first.second, c = xy[i].second.first, d = xy[i].second.second;
		imos[a][b]++; imos[a][d]--; imos[c][b]--; imos[c][d]++;
	}
	rep(i, max_h) rep(j, max_w - 1) {
		imos[i][j + 1] += imos[i][j];
	}
	rep(i, max_w) rep(j, max_h - 1) {
		imos[j + 1][i] += imos[j][i];
	} //ここまで2次元imos
	ll ans = 0;
	cout << ans << endl;
}