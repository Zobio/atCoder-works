#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	// a<bのときa % b == aなので結局gcd(b, a)に帰結する。
	if (a % b == 0)
	{
		return b;
	}
	else
	{
		return gcd(b, a % b);
	}
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main() {
	int n;
	cin >> n;
	long long ans = 1;
	for(int i = 2; i <= n; i++) {
		ans = lcm(ans, i);
	}
	cout << ans + 1 << endl;
}