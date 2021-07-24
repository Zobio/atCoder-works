#include <bits/stdc++.h>
#define MAX_ELEMENT 300000 //要変更
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000
using namespace std;

long long combi(long long n, long long k) {
  if (n == k || k == 0)
    return 1;
  else {
    return combi(n - 1, k - 1) + combi(n - 1, k);
  }
}

int main() {
	int n;
	cin >> n;
	vector<ull> c(n);
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort(c.begin(), c.end());
	ull ans = 1;
	for(int i = 0; i < n; i++) {
		ans = ans * max((ull)0, c[i] - i) % MOD;
	}
	cout << ans << endl;
}