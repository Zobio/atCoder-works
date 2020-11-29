#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] /= 2;
	}
	sort(a.begin(), a.end());
	int ans = 0;
	int count = 0;

	for(int i = a[n - 1]; i <= m; i++) {
		for(int j = 0; j < n; j++) {
			if(i % a[j] != 0 || (i / a[j]) % 2 == 0){
			break;
			}
			count++;
			if(count == n)
			ans++;
		}
		count = 0;
	}
	cout << ans << endl;
}