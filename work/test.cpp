#include <bits/stdc++.h>
using namespace std;

int main() {
    
	int N,M;
	cin>>N>>M;
	vector<vector<int>> E(N);
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	vector<int> dis(N,-1);
	
	int Q;
	cin>>Q;
	
	for(int i=0;i<Q;i++){
		int x,k;
		cin>>x>>k;
		x--;
		queue<int> q;
		q.push(x);
		dis[x] = 0;
		vector<int> vs;
		while(q.size()>0){
			int u = q.front();
			q.pop();
			vs.push_back(u);
			if(dis[u]==k){
				continue;
			}
			for(int j=0;j<E[u].size();j++){
				int v = E[u][j];
				if(dis[v]!=-1)continue;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
		int ans = 0;
		for(int j=0;j<vs.size();j++){
			ans += vs[j]+1;
			dis[vs[j]] = -1;
		}
		cout<<ans<<endl;
	}
	
    return 0;
}
