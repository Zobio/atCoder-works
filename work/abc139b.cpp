#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	a--; b--;
	cout << (b % a == 0 ? b / a : b / a + 1) << endl;
}