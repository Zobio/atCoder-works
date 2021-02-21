#include <bits/stdc++.h>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	long long x = a * 10000;
	long long y = b * 10000;
	long long r = c * 10000;
	long long ans = 0;
	long long start = x - r, end = y - r;
	while(start % 10000)start++;
	while(end % 10000)end++;
	for(long long i = start; i <= x + r; i+=10000) {
		long long height =  floor(sqrt(r * r - (x - i) * (x - i))) / 10000;
		ans += floor(a + height) - ceil(b - height) + 1;
	}
	cout << ans << endl;
}