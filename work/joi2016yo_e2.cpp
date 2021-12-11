#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<map>
using namespace std;
typedef long long Int;
typedef pair<Int, Int> P;

#define INF (1LL << 60)

vector<Int> edge[108000];
Int dist[108000];
bool zombie[108000];
bool danger[108000];
Int pcost, qcost;
Int n, m, k, s, x, a, b;

void dijkstra(Int start){
	priority_queue<P, vector<P>, greater<P> > pq;
	fill(dist, dist + 108000, INF);
	
	dist[start] = 0;
	pq.push(P(0, start));
	
	while(!pq.empty()){
		P tmp = pq.top();pq.pop();
		Int from = tmp.second;
		Int d = tmp.first;
		if(dist[from] < d)continue;
		
		for(Int i = 0;i < edge[from].size();i++){
			Int to = edge[from][i];
			if(zombie[to])continue;
			Int cost = pcost;
			if(danger[to])cost = qcost;
			if(to == n)cost = 0;
			if(dist[to] > dist[from] + cost){
				dist[to] = dist[from] + cost;
				pq.push(P(dist[to], to));
			}
		}		
	}
}

bool done[108000];
vector<Int> edges[108000];

int main(){
	cin >> n >> m >> k >> s;
	cin >> pcost >> qcost;

	queue<Int> q;

	for(Int i = 0;i < k;i++){
		cin >> x;
		zombie[x] = true;
		q.push(x);
	}
	
	for(Int i = 0;i < m;i++){
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	for(Int i = 0;i <= s;i++){
		if(q.empty())break;
		
		for(Int j = q.size() - 1;j >= 0;j--){
			Int from = q.front();q.pop();
			if(danger[from])continue;
			danger[from] = true;
			for(Int k = 0;k < edge[from].size();k++){
				q.push(edge[from][k]);
			}
		}
	}
	
	dijkstra(1);
	
	cout << dist[n] << endl;

	return 0;	
}