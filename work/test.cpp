#include <iostream>
#include <vector>
using namespace std;

#include "atcoder/dsu.hpp"

int main() {
  int N;
  cin >> N;
  vector<int> X(N), C(N);
  for (auto& x : X) cin >> x, --x;
  for (auto& x : C) cin >> x;
  atcoder::dsu uf(N);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (uf.same(i, X[i]) == false) {
      uf.merge(i, X[i]);
      continue;
    }
    int cur = C[i], v = i;
    do {
      v = X[v];
      cur = min(cur, C[v]);
    } while (v != i);
    cout << i << " " << cur << endl;
    ans += cur;
  }
  cout << ans << "\n";
}
