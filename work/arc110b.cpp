#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string t;
	cin >> t;
	long long max = 10000000000;
	for(int i = 0; i < n - 1; i++) {
		if(t[i] == '0' && t[i + 1] == '0') {
			cout << 0 << endl;
			return 0;
		}
	}
	for(int i = 0; i < n - 2; i++) {
		if(t[i] == '1' && t[i + 1] == '1' && t[i + 2] == '1') {
			cout << 0 << endl;
			return 0;
		}
	}
	for(int i = 0; i < n - 2; i++) {
		if(t[i] == '0' && t[i + 2] == '0') {
			cout << 0 << endl;
			return 0;
		}
	}
	if(t == "1") {
		cout << 2 * max << endl;
		return 0;
	}
	else if (t == "11") {
		cout << max << endl;
		return 0;
	}
	int zeroCount = 0;
	for(int i = 0; i < n; i++) {
		if(t[i] == '0')
		zeroCount++;
	}
	if(t[n - 1] == '0') {
		cout << max - zeroCount + 1 << endl;
	}
	else if (t[n - 1] == '1') {
		cout << max - zeroCount << endl;
	}
}