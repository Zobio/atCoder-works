#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k, m;
  cin >> n >> k >> m;
  int ans = n * m;
  int tmp;
  for(int i = 0; i < n - 1; i++) {
	  cin >> tmp;
	  ans -= tmp;
  }
  if(ans <= k && ans <= 0) {
	  cout << 0 << endl;
  }else if(ans <= k) {
	  cout << ans << endl;
  }else{
	  cout << -1 << endl;
  }
}