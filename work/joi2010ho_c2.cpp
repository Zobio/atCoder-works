#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long L;
    cin >> N >> L;
    vector<long long> a(N+2, 0);
    for (int i = 1; i <= N; ++i) cin >> a[i];

    // 初期条件
    vector<long long> dp(N+2, 0);
    for (int i = 1; i <= N; ++i) {
        if (a[i] > a[i-1] && a[i] > a[i+1]) dp[i] = L - a[i];
    }

    // 左右から DP
    for (int i = 1; i <= N; ++i) {
        if (a[i] < a[i-1]) dp[i] = max(dp[i], dp[i-1] + (L - a[i]));
    }
    for (int i = N; i >= 1; --i) {
        if (a[i] < a[i+1]) dp[i] = max(dp[i], dp[i+1] + (L - a[i]));
    }

    // 答え
    long long res = 0;
    for (int i = 1; i <= N; ++i) res = max(res, dp[i]);
    cout << res << endl;
}