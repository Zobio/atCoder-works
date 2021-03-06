#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	int ans = 0;
	vector<int> x(n);
	vector<int> y(n);
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++){
		cin >> y[i];
	}
	for(int i = 0; i < n; i++) {
		if(x[i] - y[i] > 0) ans += x[i] - y[i];
	}
	cout << ans << endl;
}