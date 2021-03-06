#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	double n;
	cin >> n;
	double old = n;
	n--;
	double ans = 1;
	for(int i = 0; i < old - 1; i++) {
		ans *= old;
		ans /= n;
		n--;
	}
	cout << setprecision(15) << fixed;
	cout << ans << endl;
}