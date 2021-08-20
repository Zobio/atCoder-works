#include <bits/stdc++.h>
#define MAX_ELEMENT 50000 //要変更
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000
using namespace std;

vector<int> par(MAX_ELEMENT);
vector<int> rnk(MAX_ELEMENT);

// n要素で初期化
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rnk[i] = 0;
    }
}

//木の根を求める
int root(int x) {
    if (par[x] == x) {
        return x;
    }else{
        return par[x] = root(par[x]);
    }
}

//xとyの属する集合を併合
void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) {
        return;
    }

    if (rnk[x] < rnk[y]) {
        par[x] = y;
    }else{
        par[y] = x;
        if (rnk[x] == rnk[y]) {
            rnk[x] += 1;
        }
    }
}
// xとyが同じ集合に属するか否か
bool same(int x, int y) {
    return root(x) == root(y);
}

int main() {
    
}