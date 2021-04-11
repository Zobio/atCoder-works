#include<bits/stdc++.h>
using namespace std;
string a,b,c,aa,bb,cc;
int n[30];
bool f[30],g[20];
void dfs(int x){
	if(x==26){
		aa=bb=cc="";
		for(unsigned int i=0;i<a.size();++i)aa+=n[a[i]-'a']+'0';
		for(unsigned int i=0;i<b.size();++i)bb+=n[b[i]-'a']+'0';
		for(unsigned int i=0;i<c.size();++i)cc+=n[c[i]-'a']+'0';
		if(aa[0]=='0'||bb[0]=='0'||cc[0]=='0')return;
		if(stoll(aa)+stoll(bb)==stoll(cc)){
			cout<<aa<<endl<<bb<<endl<<cc;
			exit(0);
		}
		return;
	}
	if(!f[x]){dfs(x+1);return;}
	for(int i=0;i<10;++i){
		if(g[i])continue;
		n[x]=i;
		g[i]=true;
		dfs(x+1);
		g[i]=false;
	}
}
int main(){
	cin>>a>>b>>c;
	for(unsigned int i=0;i<a.size();++i)f[a[i]-'a']=true;
	for(unsigned int i=0;i<b.size();++i)f[b[i]-'a']=true;
	for(unsigned int i=0;i<c.size();++i)f[c[i]-'a']=true;
	for(int i=0;i<26;++i)
		if(f[i]){
			dfs(i);
			break;
		}
	puts("UNSOLVABLE");
	return 0;
}