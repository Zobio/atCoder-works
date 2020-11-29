#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	// a<bのときa % b == aなので結局gcd(b, a)に帰結する。
	cout << a << " " << b << endl;
	if (a % b == 0) {
		return b;
	}else{
		return gcd(b, a % b);
	}
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << "GCD: " << gcd(n, m) << endl;
}