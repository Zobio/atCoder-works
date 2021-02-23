#include <bits/stdc++.h>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	long long x = a * 10000;
	long long y = b * 10000;
	long long r = c * 10000;
	long long ans = 0;
	long long start = x - r, end = x + r;
	while(start % 10000)start++;
	cout << "start: " << start << " end: " << end << endl;
	for(long long i = start; i <= end; i+=10000) {
		if(sqrt(r * r - (x - i) * (x - i)) < 0) continue;
		long long height = sqrt(r * r - (x - i) * (x - i));
		cout << y << " " << height << endl;
		ans += (y + height) / 10000 + (y - height) / 10000 + 1;
		cout << (y + height) / 10000 << " " << (y - height) / 10000 << endl;
		cout << "ans: " << ans << endl;
	}
	cout << ans << endl;
}