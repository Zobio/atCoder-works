#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	long double a, b, x;
	cin >> a >> b >> x;
	long double ans = 0;
	if(a * a * b / 2 > x) {
		ans = atan(a * b * b / (2 * x));
	}else{
		ans = atan(2 * (a * a * b - x) / (a * a * a));
	}
	ans /= 3.141592653589793238462643383279502884197169399375;
	ans *= 180;
	cout << setprecision(15) << fixed << ans << endl;
}