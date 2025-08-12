#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Union-Find構造体の定義
typedef struct {
    int *parent;    // 親ノードまたはサイズ情報（負の値はサイズ）
    int size;       // 全体のサイズ
    int groups;     // グループ数
} UnionFind;

typedef struct {
    int from;
    int to;
    int cost;
} Edge;

// Union-Find構造体の初期化
UnionFind* uf_create(int n) {
    UnionFind *uf = (UnionFind*)malloc(sizeof(UnionFind));
    if (uf == NULL) {
        printf("メモリ割り当てエラー\n");
        exit(1);
    }
    
    uf->parent = (int*)malloc(sizeof(int) * n);
    if (uf->parent == NULL) {
        printf("メモリ割り当てエラー\n");
        free(uf);
        exit(1);
    }
    
    uf->size = n;
    uf->groups = n;
    
    // 初期化：各要素が自分自身を根とし、サイズは1
    for (int i = 0; i < n; i++) {
        uf->parent[i] = -1;  // 負の値でサイズを表現
    }
    
    return uf;
}

// Union-Find構造体のメモリ解放
void uf_destroy(UnionFind *uf) {
    if (uf != NULL) {
        free(uf->parent);
        free(uf);
    }
}

// 根を見つける関数（経路圧縮あり）
int uf_find(UnionFind *uf, int x) {
    if (uf->parent[x] < 0) {
        return x;  // 負の値なら根
    } else {
        // 経路圧縮
        uf->parent[x] = uf_find(uf, uf->parent[x]);
        return uf->parent[x];
    }
}

// 2つの要素を合併する関数（Union by Size）
void uf_unite(UnionFind *uf, int x, int y) {
    int root_x = uf_find(uf, x);
    int root_y = uf_find(uf, y);
    
    // 既に同じグループの場合
    if (root_x == root_y) {
        return;
    }
    
    // グループ数を減らす
    uf->groups--;
    
    // サイズの大きい方を根にする（Union by Size）
    if (uf->parent[root_x] > uf->parent[root_y]) {
        // root_xの方がサイズが小さい（負の値なので）
        int temp = root_x;
        root_x = root_y;
        root_y = temp;
    }
    
    // サイズを合算
    uf->parent[root_x] += uf->parent[root_y];
    // root_yをroot_xの子にする
    uf->parent[root_y] = root_x;
}

// 2つの要素が同じグループかどうか判定
bool uf_is_same(UnionFind *uf, int x, int y) {
    return uf_find(uf, x) == uf_find(uf, y);
}

// グループのサイズを取得
int uf_get_size(UnionFind *uf, int x) {
    int root = uf_find(uf, x);
    return -(uf->parent[root]);  // 負の値なので符号を反転
}

// グループ数を取得
int uf_get_group_count(UnionFind *uf) {
    return uf->groups;
}

// 全ての根を取得（呼び出し元で配列を用意する必要あり）
int uf_get_roots(UnionFind *uf, int *roots) {
    int count = 0;
    for (int i = 0; i < uf->size; i++) {
        if (uf->parent[i] < 0) {
            roots[count++] = i;
        }
    }
    return count;
}

// デバッグ用：内部状態を表示
void uf_debug_print(UnionFind *uf) {
    printf("=== Union-Find Debug Info ===\n");
    printf("Size: %d, Groups: %d\n", uf->size, uf->groups);
    printf("Index:  ");
    for (int i = 0; i < uf->size; i++) {
        printf("%3d ", i);
    }
    printf("\n");
    printf("Parent: ");
    for (int i = 0; i < uf->size; i++) {
        printf("%3d ", uf->parent[i]);
    }
    printf("\n");
    printf("Root:   ");
    for (int i = 0; i < uf->size; i++) {
        printf("%3d ", uf_find(uf, i));
    }
    printf("\n");
    printf("=============================\n");
}

bool comp(Edge* e1, Edge* e2) {
    if(e1 -> cost < e2 -> cost) return -1;
    else return 1;
    return 0;
}

// 使用例
int main() {
    int v, e;
    scanf("%d %d", &v, &e);
    Edge es[e + 100]; //念の為100くらい余分にメモリ確保
    for(int i = 0; i < e; i++) {
        
    }
    return 0;
}