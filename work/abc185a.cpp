#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = 0;
	if(a < b)
	ans = a;
	else
	ans = b;
	if(ans > c)
	ans = c;
	if(ans > d)
	ans = d;
	cout << ans << endl;
}