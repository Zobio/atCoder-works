#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n; cin >> n;
	int top = 0, bottom = 1001;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a.rbegin(), a.rend());
	sort(b.begin(), b.end());
	cout << max(0, b[0] - a[0] + 1) << endl;
}