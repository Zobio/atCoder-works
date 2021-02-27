#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> l(n);
	for(int i = 0; i < n; i++) {
		cin >> l[i];
	}
	int ans = 1;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += l[i];
		if(sum <= x) {
			ans++;
		}else{
			break;
		}
	}
	cout << ans << endl;
}