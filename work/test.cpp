#include<bits/stdc++.h>
using namespace std;
#include<atcoder/segtree>
using namespace atcoder;

int op(int a,int b){ return a^b;};
int e(){return 0;};

int main(){
  int N,Q;cin>>N>>Q;
  segtree<int,op,e> X(N);
  for(int i=0;i<N;i++){
    int a;cin>>a;
    X.set(i,a);
  }
  
  while(Q--){
    int t,x,y;cin>>t>>x>>y;
    x--;
    if(t==1) X.set(x,X.get(x)^y);
    else cout<<X.prod(x,y)<<endl;
  }
}
