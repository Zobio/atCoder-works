#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 1000000007LL
#define INF 1LL << 60

ll n;
vector<vector<ll>> g;

ll bfs(ll st) {
	// BFS のためのデータ構造
	vector<int> dist(n, -1); // 全頂点を「未訪問」に初期化
	queue<int> que;
	// 初期条件 (頂点 st を初期ノードとする)
	dist[st] = 0;
	que.push(st); // st を橙色頂点にする
	// BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        // v から辿れる頂点をすべて調べる
        for (int nv : g[v]) {
            if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない
            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
	ll ret = 0;
    // 結果出力 (各頂点の頂点 st からの距離を見る)
    rep(i, n) ret += dist[i];
	return ret;
}

int main() {
	cin >> n;
	g.resize(n);
	rep(i, n - 1) {
		ll a, b; cin >> a >> b;
		a--; b--;
		g[a].push_back(b); g[b].push_back(a);
	}
	rep(i, n) cout << bfs(i) << endl;
}