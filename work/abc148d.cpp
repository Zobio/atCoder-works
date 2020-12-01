#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int count = 1;
	for(int i = 0; i < n; i++) {
		if(a[i] == count) {
			count++;
		}
	}
	if(count == 1) {
		cout << -1 << endl;
	}else{
	cout << n - count + 1 << endl;
	}
}