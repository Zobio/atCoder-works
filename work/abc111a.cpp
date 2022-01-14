#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
  for(auto &a : s) {
    if(a == '1') cout << 9;
    else if(a== '9') cout << 1;
    else cout << a;
  }cout << endl;
}