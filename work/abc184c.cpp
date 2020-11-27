#include <bits/stdc++.h>
using namespace std;

int main() {
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int r = r2 - r1;
	int c = c2 - c1;
	if(!r && !c) {
		cout << 0 << endl;
	}
	else if (r == c || r == -c || abs(r) + abs(c) <= 3) {
		cout << 1 << endl;
	}
	else if ((r ^ c ^ 1) & 1) {
		cout << 2 << endl;
	}
	else if (abs(r2 - r1) + abs(c2 - c1) <= 6) {
		cout << 2 << endl;
	}
	else if(abs((r1 + c1) - (r2 + c2)) <= 3 || abs((r1 - c1) - (r2 - c2)) <= 3) {
		cout << 2 << endl;
	}else{
		cout << 3 << endl;
	}
}