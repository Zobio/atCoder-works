#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++) {
		if(i & 1) {
			if(s[i] < 'A' || s[i] > 'Z') {
				cout << "No" << endl;
				return 0;
			}
		}else{
			if(s[i] < 'a' || s[i] > 'z') {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}