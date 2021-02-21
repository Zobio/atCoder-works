#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, s, d;
	cin >> n >> s >> d;
	int power, time;
	for(int i = 0; i < n; i++) {
		cin >> time >> power;
		if(time < s && power > d) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}