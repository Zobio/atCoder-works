#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> a(3);
  for(int i = 0; i < 3; i++) cin >> a[i];
  sort(a.rbegin(), a.rend());
  cout << a[0] * 10 + a[1] + a[2] << endl;
}