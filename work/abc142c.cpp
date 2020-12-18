#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	/*
	for(int i = 0; i < n; i++) {
		iterator itr = find(a.begin(), a.end(), i);
		cout << itr - a.begin() << endl;
	}
	*/
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[j] == i) {
				cout << j + 1 << " ";
				break;
			}
		}
	}
	cout << endl;
}