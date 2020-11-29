#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	// a<bのときa % b == aなので結局gcd(b, a)に帰結する。
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
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] /= 2;
	}
	sort(a.begin(), a.end());
	while(a[0] % 2 == 0) {
		for(int i = 0; i < n; i++) {
			if(a[i] % 2 != 0) {
			cout << "0" << endl;
			return 0;
			}
			a[i] /= 2;
		}
		m /= 2;
	}
	for (int i = 0; i < n; i++){
		if (a[i] % 2 == 0) {
			cout << "0" << endl;
			return 0;
		}
	}
	long long base = 1;
	for(int i = 0; i < n; i++) {
		base = lcm(base, a[i]);
	}
	if(base > m){
	cout << 0 << endl;
	}else{
	cout << (m / base + 1) / 2 << endl;
	}
}