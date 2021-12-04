#include<bits/stdc++.h> 
using namespace std;
int n,m,d[1010][1010],z;
int fx[5]={0,-1,0,1,0},fy[5]={0,0,1,0,-1};
char c[1010][1010];
queue<int> q;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
			cin>>c[i][j];
    		if(c[i][j]=='#'){
    			q.push(i);
    			q.push(j);
    			d[i][j]=0;
			}
		}
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		int y=q.front();q.pop();
		z=d[x][y];
		for(int i=1;i<=4;i++){
			int tx=x+fx[i],ty=y+fy[i];
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&c[tx][ty]=='.'){
				d[tx][ty]=d[x][y]+1;
				c[tx][ty]='#';
				q.push(tx);q.push(ty);
			}
		}
	}
	cout<<z<<endl;
    return 0;
}