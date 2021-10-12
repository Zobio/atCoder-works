#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (auto& x : A) cin >> x;
  for (auto& x : B) cin >> x;
  int MAX = 3000;
  vvll dp((N + 1, vector(MAX + 1, ll{0})));
  dp[0][0] = 1;
  rep(i, N + 1) {
    rep(j, MAX) dp[i][j + 1] += dp[i][j];
    if (i != N) {
      for (int j = A[i]; j <= B[i]; j++) dp[i + 1][j] += dp[i][j];
    }
  }
  cout << dp[N][MAX].val() << "\n";
}