#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main() {
	int p, q, r;
	cin >> p >> q >> r;
	int ans = min(min(p + q, q + r), p + r);
	cout << ans << endl;
}