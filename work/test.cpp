#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> par;

  UnionFind(int sz) {
    par.resize(sz, -1);
  }
  int root(int pos) {
    if(par[pos] < 0) return pos;
    else return par[pos] = root(par[pos]);
  }
  bool unite(int u, int v) {
    u = root(u); v = root(v);
    if(u == v) return false;
    par[v] = u;
    return true;
  }
  bool same(int u, int v) {
    return root(u) == root(v);
  }
};

int main(){
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  // 前計算
  vector<vector<int>> power(2001, vector<int>(m + 1));
  for(int i = 0; i <= 2000; i++) power[i][0] = 1;
  for(int i = 2; i <= 2000; i++) {
    for(int j = 1; j <= m; j++) {
      power[i][j] = power[i][j - 1] * i;
      power[i][j] %= m;
    }
  } 
  vector<int> mx(2001, -1);
  for(int i = 2; i <= 2000; i++){
    for(int j = 1; j <= m; j++){
      mx[i] = max(mx[i], power[i][j]);
    }
  }

  // プリム法
  priority_queue<tuple<int,int,int>> q;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++) {
      q.push({mx[a[i] + a[j]], i, j});
    }
  }

  int res = 0;
  UnionFind uf(n);
  int edge_cnt = 0;
  while(edge_cnt < n - 1) {
    auto [cost, u, v] = q.top(); q.pop();
    if(uf.same(u, v)) continue;

    res += cost;
    uf.unite(u, v);
    edge_cnt++;
  }

  cout << res << '\n';

  return 0;
}