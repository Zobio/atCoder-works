#include <iostream>
#include <vector>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

long long dp[100][2];

int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    
    for (int i = 0; i < 100; ++i) dp[i][0] = dp[i][1] = -1;
    dp[45][0] = 0;
    for (int d = 44; d >= 0; --d) {
        long long mask = 1LL<<d;
        int num = 0;
        for (int i = 0; i < N; ++i) if (A[i] & mask) ++num;
        
        if (dp[d+1][1] >= 0) chmax(dp[d][1], dp[d+1][1] + mask * max(num, N-num));
        if (dp[d+1][0] >= 0) {
            if (K & (1LL<<d)) {
                chmax(dp[d][1], dp[d+1][0] + mask * num);
                chmax(dp[d][0], dp[d+1][0] + mask * (N-num));
            }
            else {
                chmax(dp[d][0], dp[d+1][0] + mask * num);
            }
        }
    }
    cout << max(dp[0][0], dp[0][1]) << endl;
}