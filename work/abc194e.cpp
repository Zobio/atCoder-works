#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> st(n, 1000000000);
	vector<int> en(n, 0);
	vector<bool> yet(n, false);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		yet[a[i]] = true;
		st[a[i]] = min(max(0, i - m + 1), st[a[i]]);
		en[a[i]] = max(min(n - 1, i + m - 1), en[a[i]]);
	}
	for(int i = 0; i < n; i++) {
		if((st[i] != 0 || en[i] != n - 1) || !yet[i]) {
			cout << i << endl;
			return 0;
		} 
	}
}