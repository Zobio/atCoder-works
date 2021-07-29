#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ll n;
	cin >> n;
	ll cnt = 0;
	for(ll a = 1; a < n; a++) {
		cnt += n / a;
		if(n % a == 0) cnt--;
	}
	cout << cnt << endl;
}