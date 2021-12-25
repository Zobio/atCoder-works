#include <bits/stdc++.h>
using namespace std;

int main(){
    // 頂点数N、始点の頂点番号s
    int N, s;
    // 隣接リスト。
    // edges[i]の要素に(j, c)が含まれる時、iからjにコストcの辺が存在
    vector<vector<pair<int, int>>> edges(N);

    vector<int> dist(N, 1e9);
    dist[s] = 0;
    deque<int> que;
    que.push_back(s);

    while(que.size()){
        int i = que.front(); que.pop_front();
        for(auto [j, c] : edges[i]){
            int d = dist[i] + c;
            if(d < dist[j]){
                dist[j] = d;
                if(c){
                    que.push_back(j);
                }else{
                    que.push_front(j);
                }
            }
        }
    }
}