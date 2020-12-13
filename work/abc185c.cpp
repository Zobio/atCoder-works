#include <bits/stdc++.h>
using namespace std;

int main() {
	int l;
	cin >> l;
	long long r = 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11;
	vector<bool> yet(12, true);
	long long ans = 1;
	for(int i = l - 1; i > l - 12; i--) {
		ans *= i;
		for(int j = 2; j <= 11; j++) {
			if(yet[j] && ans % j == 0) {
				r /= j;
				ans /= j;
				yet[j] = false;
			}
		}
	}
	ans /= r;
	cout << ans << endl;
}