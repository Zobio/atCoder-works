#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,w;
  cin >> a >> b >> w;
  int m=1e9,M=0;
  for(int n=1;n<=1000000;n++){
    if(a*n<=1000*w && 1000*w<=b*n){
      m=min(m,n);
      M=max(M,n);
    }
  }
  if(M==0)cout << "UNSATISFIABLE";
  else cout << m << ' ' << M;
}
