#include <bits/stdc++.h>
using namespace std;

int main() {
	long long l, r;
	cin >> l >> r;
	long long ans = 2019;
	for(long long i = l; i < l + 2019; i++) {
		for(long long j = r; j > r - 2019; j--) {
			if(i < j) ans = min(ans, ((i % 2019) * (j % 2019)) % 2019);
		}
	}
	cout << ans << endl;
}