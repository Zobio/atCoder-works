#include <iostream>
#include <vector>
#include <atcoder/segtree>

using namespace std;

constexpr int INF = 100000000;

// 区間最大値を得るセグメント木の準備
using S = int;
int op(int a, int b) { return max(a, b); }
int e() { return -INF; }
using segtree = atcoder::segtree<S, op, e>;

void calc(const int N, const vector<int> &P, vector<int> &D) {
    // chmin(D[i], P[i] + i - max_{j < i && P[j] < P[i]} {P[j] + j}
    segtree segment_tree(N);
    for (int i = 0; i < N; ++i) {
        D[i] = min(D[i], P[i] + i - segment_tree.prod(0, P[i]));
        segment_tree.set(P[i] - 1, P[i] + i);
    }
}

int main() {

    int N;
    cin >> N;
    vector<int> P(N);
    for (auto &&p : P) cin >> p;
    vector<int> D(N, INF);

    // j < i かつ P[j] < P[i] なる j について計算
    calc(N, P, D);

    // j < i かつ P[j] > P[i]
    for (auto &&p : P) p = N + 1 - p;
    calc(N, P, D);

    // j > i かつ P[j] > P[i]
    reverse(begin(P), end(P));
    reverse(begin(D), end(D));
    calc(N, P, D);

    // j > i かつ P[j] < P[i]
    for (auto &&p : P) p = N + 1 - p;
    calc(N, P, D);

    // 反転を直して出力
    reverse(begin(P), end(P));
    reverse(begin(D), end(D));
    for (int i = 0; i < N; ++i) cout << D[i] << " ";
    cout << endl;

    return 0;
}
