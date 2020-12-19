#include <bits/stdc++.h>
using namespace std;

int main() {
	string n;
	cin >> n;
	for(int i = 0; i < n.length(); i++) {
		if(i % 2 == 0) {
			if(n[i] == 'L') {
				cout << "No" << endl;
				return 0;
			}
		}else{
			if(n[i] == 'R') {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}