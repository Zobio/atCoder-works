#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	// a<bのときa % b == aなので結局gcd(b, a)に帰結する。
	if (a % b == 0) {
		return b;
	}else{
		return gcd(b, a % b);
	}
}

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << "GCD: " << gcd(n, m) << endl;
}