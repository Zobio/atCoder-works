#include<bits/stdc++.h>

using namespace std;

int l;
string s,t;
vector<string> res;

void find(int fl){
  cout << bitset<4>(fl) << " "  << t.size() <<  endl;
  if(fl==0){
    res.push_back(t);
    return;
  }
  for(int i=0;i<l;i++){
    if(fl&(1<<i)){
      t.push_back(s[i]);
      find(fl^(1<<i));
      t.pop_back();
    }
  }
}

int main(){
  int k;
  cin >> s >> k;
  l=s.size();
  find((1<<l)-1);
  sort(res.begin(),res.end());
  unique(res.begin(),res.end());
  cout << res[k-1] << '\n';
  return 0;
}
