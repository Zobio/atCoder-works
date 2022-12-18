#include <bits/stdc++.h>
using namespace std;

int dfs(int cur,vector<int> a){
	
	if(cur==-1)return 0;
	vector<int> S,T;
	
	for(int i=0;i<a.size();i++){
		if(((a[i]>>cur)&1)==0)S.push_back(a[i]);
		else T.push_back(a[i]);
	}
	
	if(S.size()==0)return dfs(cur-1,T);
	if(T.size()==0)return dfs(cur-1,S);
	return min(dfs(cur-1,S),dfs(cur-1,T)) | (1<<cur);
	
}

int main() {
    
	int N;
	cin>>N;
	
	vector<int> a(N);
	for(int i=0;i<N;i++)cin>>a[i];
	
	cout<<dfs(29,a)<<endl;
	
	return 0;
}
