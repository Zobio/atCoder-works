#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int max = 1;
	int a;
	for(int i = 0; i < n; i++) {
		cin >> a;
		if(a + 1 < max) {
			cout << "No" << endl;
			return 0;
		}
		if (a > max) {
			max = a;
		}
	}
	cout << "Yes" << endl;
}