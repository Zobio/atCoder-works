#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ll n;
	cin >> n;
	ll ok = 1000000, ng = -1;
	while(abs(ok - ng) > 1) {
		ll mid = (ok + ng) / (ll)2;
		if(mid * mid + mid >= (ll)2 * n) ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
}