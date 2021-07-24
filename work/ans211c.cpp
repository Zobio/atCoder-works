#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> dp(9);
  dp[0] = 1;
  const int mod = 1000000007;
  string t = "chokudai";
  rep(i,n)rep(j,8) {
    if (s[i] == t[j]) {
      (dp[j+1] += dp[j]) %= mod;
    }
  }
  cout << dp[8] << endl;
  return 0;
}