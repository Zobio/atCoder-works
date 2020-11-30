#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,r,s,p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;
  int ans=0;
  for(int i=0;i<n;i++){
    if(i>=k && t[i]==t[i-k]){
		t[i]='k';
		continue;
	}
    ans += t[i] == 'r' ? p : t[i] == 's' ? r : s;
  }
  cout << ans << endl;
}
   
    