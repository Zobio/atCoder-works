#include <bits/stdc++.h>
#define MAX_ELEMENT 50000 //要変更
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000
using namespace std;

vector<int> par(MAX_ELEMENT);
vector<int> rnk(MAX_ELEMENT);

int si = 0;

// n要素で初期化
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rnk[i] = 0;
    }
}

//木の根を求める
int root(int x) {
    if (par[x] == x) {
        return x;
    }else{
        return par[x] = root(par[x]);
    }
}

//xとyの属する集合を併合
void unite(int x, int y) {
	x = root(x);
    y = root(y);
    if (x == y) {
        return;
    }

    if (rnk[x] < rnk[y]) {
        par[x] = y;
    }else{
        par[y] = x;
        if (rnk[x] == rnk[y]) {
            rnk[x] += 1;
        }
    }
}
// xとyが同じ集合に属するか否か
bool same(int x, int y) {
    return root(x) == root(y);
}

void show(set<int> v) {
	for(auto a : v) cout << a + 1 << " ";
}

int main() {
    int n, m;
	cin >> n >> m;
	init(n);
	vector<pair<int, int>> v(m);
	int ans = 0;
	for(int i = 0; i < m; i++) {
		cin >> v[i].first >> v[i].second;
		v[i].first--; v[i].second--;
		unite(v[i].first, v[i].second);
	}
	vector<int> edge(n);
	vector<set<int>> num(n);
	for(int i = 0; i < m; i++) {
		//要素数
		num[root(v[i].first)].insert(v[i].first);
		num[root(v[i].second)].insert(v[i].second);
		//辺の数
		if (root(v[i].first) != v[i].first) {
			edge[root(v[i].first)]++;
		}
		//グラフは連結なので、片方だけedgeを増やせばよい(firstが根の場合のみ、else ifが実行される)
		else if (root(v[i].second) != v[i].second)
		{
			//cout << v[i].second + 1 << endl;
			edge[root(v[i].second)]++;
		}
	}
	for(int i = 0; i < n; i++) {
		if(root(i) != i) {
			continue;
		}
		num[i].insert(i);
		//cout << i + 1 << " edge: " << edge[i] << " size: " << num[i].size() << endl;
		//show(num[i]); cout << endl;
		if(edge[i] + 1 == num[i].size()) ans++;
	}
	cout << ans << endl;
}