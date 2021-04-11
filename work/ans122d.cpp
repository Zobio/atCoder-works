#include <iostream>
#include <vector>
using namespace std;

// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

// mod add
const int MOD = 1000000007;
void add(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

// 0: dammy, 1: 'A', 2: 'G', 3: 'C', 4: 'T'
// "AGC, GAC, ACG", "A*GC", "AG*C" を含まない (012, 102, 021 を禁止)
long long solve(int N) {
    auto dp = make_vec<long long>(N+1, 5, 5, 5); // dp[i文字][3文字前][2文字前][1文字前]
    dp[0][0][0][0] = 1;
    for (int n = 0; n < N; ++n) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                 for (int k = 0; k < 5; ++k) {
                     for (int l = 1; l < 5; ++l) {
                         if (i == 1 && j == 2 && l == 3) continue;
                         if (i == 1 && k == 2 && l == 3) continue;
                         if (j == 1 && k == 2 && l == 3) continue;
                         if (j == 2 && k == 1 && l == 3) continue;
                         if (j == 1 && k == 3 && l == 2) continue;
                         add(dp[n+1][j][k][l], dp[n][i][j][k]);
                     }
                }
            }
        }
    }
    long long res = 0;
    for (int i = 1; i < 5; ++i)
        for (int j = 1; j < 5; ++j)
            for (int k = 1; k < 5; ++k)
                add(res, dp[N][i][j][k]);
    return res;
}

int main() {
    int N;
    while (cin >> N) cout << solve(N) << endl;
}