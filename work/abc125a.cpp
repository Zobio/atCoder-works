#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int a, b, t;
	cin >> a >> b >> t;
	int f = a, ans = 0;
	while(a <= t)
		a += f, ans += b;
	cout << ans << endl;
}