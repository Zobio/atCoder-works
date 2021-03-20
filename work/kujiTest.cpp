#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	for(double i = 2; i <= 10000000; i *= 2) {
		double ans = 1;
		for(int j = 0; j < i; j++) {
			ans *= (double)((i - 1) / i);
		}
		cout << "n: " <<  i << " " << 1.0 - ans << endl;
	}
}