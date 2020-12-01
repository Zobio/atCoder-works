#include <bits/stdc++.h>
using namespace std;
using ll =long long;

	ll gcd(int a, int b)
{
	// a<bのときa % b == aなので結局gcd(b, a)に帰結する。
	if (a % b == 0) {
		return b;
	}else{
		return gcd(b, a % b);
	}
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int main() {
	ll n, m;
	cin >> n >> m;
	cout << lcm(n, m) << endl;
}