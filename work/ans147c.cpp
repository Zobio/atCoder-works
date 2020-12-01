#include <iostream>
#include <vector>

using namespace std;

struct ev {
  int x, y;
};

int main() {
  int N;
  cin >> N;

  vector<vector<ev>> evs(N);
  for (int i = 0; i < N; ++i) {
    int A;
    cin >> A;
    for (int j = 0; j < A; ++j) {
      int x, y;
      cin >> x >> y;
      evs[i].push_back({x - 1, y});
    }
  }

  int res = 0;
  for (int i = 0; i < (1 << N); ++i) {
    int cnt = 0;
    for (int j = 0; j < N; ++j) {
      if (!(i & (1 << j))) continue;
      for (int k = 0; k < evs[j].size(); ++k) if (((i >> evs[j][k].x) & 1) != evs[j][k].y) goto loop_end;
      cnt++;
    }
    res = max(cnt, res);
    loop_end:;
  }

  cout << res << endl;
}
