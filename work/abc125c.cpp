#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

long long gcd(long long a, long long b)
{
	if(a == 0 || b == 0) return a == 0 ? b : a; 
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

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> l(n);
	l[0] = 0;
	vector<ll> r(n + 1);
	r[n] = 0;
	for(int i = 1; i < n; i++) {
		l[i] = gcd(l[i - 1], a[i - 1]);
	}
	for(int i = n - 1; i >= 0; i--) {
		r[i] = gcd(r[i + 1], a[i]);
	}
	ll ans = 1;
	for(int i = 0; i < n; i++) {
		if(ans < gcd(l[i], r[i + 1])) ans = gcd(l[i], r[i + 1]);
	}
	cout << ans << endl;
}