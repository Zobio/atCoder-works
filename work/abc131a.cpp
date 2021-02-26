#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	for(int i = 1; i < 4; i++) {
		if(s[i -1] == s[i]) {
			cout << "Bad" << endl;
			return 0;
		}
	}
	cout << "Good" << endl;
}