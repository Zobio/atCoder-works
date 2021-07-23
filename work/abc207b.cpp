#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ull a, b, c, d;
	cin >> a >> b >> c >> d;
	ll cnt = 0;
	ull blue = a, red = 0;
	while(true) {
		if(blue <= red * d) {
			cout << cnt << endl;
			return 0;
		}
		if(cnt > 2000000 && b > c) {
			cout << -1 << endl;
			return 0;
		}
		cnt++;
		blue += b; red += c;
	}
}