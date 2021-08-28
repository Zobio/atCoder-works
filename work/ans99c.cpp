#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 110000;

int dp[MAX_N]; // dp[i] が i についての答え

int main() {
    int N;
    cin >> N;

    // 初期化
    for (int i = 0; i < MAX_N; ++i) dp[i] = -1;
    dp[0] = 0;
    queue<int> que;
    que.push(0);

    // BFS
    while (!que.empty()) {
        int v = que.front();
		cout << que.front() << " " << dp[que.front()] << endl;
        que.pop();

        for (int pow6 = 1; v + pow6 <= N; pow6 *= 6) {
            if (dp[v + pow6] == -1) {
                dp[v + pow6] = dp[v] + 1;
                que.push(v + pow6);
            }
        }
        for (int pow9 = 1; v + pow9 <= N; pow9 *= 9) {
            if (dp[v + pow9] == -1) {
                dp[v + pow9] = dp[v] + 1;
                que.push(v + pow9);
            }
        }
    }

    cout << dp[N] << endl;
}