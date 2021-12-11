#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int M=1e7;
int N,Q,a[M];

int f(string s){
	int t=0;
	for(int i=N-1;i>=0;i--) t=t*3+(s[i]-'A');
	return t;
}

int main(){
	fill(a,a+M,-1);
	cin>>N>>Q;
	queue<int> q;
	for(int i=0;i<=N;i++) for(int j=0;i+j<=N;j++){
		int t=f(string(i,'A')+string(j,'B')+string(N-i-j,'C'));
		a[t]=0;
		q.push(t);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		int x=0,y=1;
		for(int i=0;i<N;i++){
			x=x*3+u/y%3;
			y*=3;
			int v=u/y*y+x;
			if(a[v]<0){
				a[v]=a[u]+1;
				q.push(v);
			}
		}
	}
	for(int i=0;i<Q;i++){
		string s;
		cin>>s;
		cout<<a[f(s)]<<endl;
	}
}