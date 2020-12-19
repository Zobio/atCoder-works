#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> unhappy;
	int fl = 0;
	if(s[0] == 'L') {
		fl++;
	}
	if(n != 1) {
		if(s[0] == 'R' && s[1] == 'L') {
			fl++;
		}
	} 
	for(int i = 1; i < n - 1; i++) {
		if(s[i] == 'L' && s[i - 1] == 'R') {
			unhappy.push_back(i);
		}
		else if(s[i] == 'R' && s[i + 1] == 'L') {
			unhappy.push_back(i);
		}
	}
	if (n != 1 && s[n - 1] == 'R') {
		fl++;
	}
	if (n != 1) {
		if (s[n - 1] == 'L' && s[n - 2] == 'R') {
			fl++;
		}
	}
	int un = unhappy.size();
	if(un >= 2 * k) {
		cout << n - (un - 2 * k + fl) << endl;
		return 0;
	}
	if (un % 2 == 1)
		un++;
	if(fl == 0) {
		cout << n << endl;
	}
	if(fl == 1) {
		if(un / 2 == k)
		cout << n - 1 << endl;
		else
		cout << n << endl;
	}
	if(fl == 2) {
		if(un / 2 == k)
		cout << n - 2 << endl;
		else if(un / 2 + 1 == k)
		cout << n - 1 << endl;
		else
		cout << 0 << endl;
	} //「端っこだけ」の操作にしか対応できていない
}