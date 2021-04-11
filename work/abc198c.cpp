#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ull r, x, y;
	cin >> r >> x >> y;
	if(r * r == x * x + y * y) {
		cout << 1 << endl; return 0;
	}
	if(2 * r * r >= x * x + y * y) {
		cout << 2 << endl; return 0;
	}
	for(ull ans = 0;;ans++) {
		if(ans * ans * r * r >= x * x + y * y) {
			cout << ans << endl;
			return 0;
		}
	}
}