#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;

    UnionFind() { }
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	const int MAX = 210000;
	UnionFind uf(MAX);
	for (int i = 0, j = n-1; i < j; ++i, --j) {
        uf.merge(a[i], a[j]);
    }
	long long res = 0;
	for (int v = 0; v < MAX; ++v) {
        if (uf.root(v) == v) {
            res += uf.size(v) - 1;
        }
    }
	cout << res << endl;
}