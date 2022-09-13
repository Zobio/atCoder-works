#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll a, b, c, d; cin >> a >> b >> c >> d;
	if((a == 37 && b >= 5) || a > 37) cout << 2 << endl;
	else if(a < c || (a == c && b < d)) cout << 0 << endl;
	else cout << 1 << endl;
}