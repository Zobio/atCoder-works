#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ll n;
	cin >> n;
	set<ll> a;
	for(int i = 1; i <= sqrt(n) + 1; i++) {
		if(n % i == 0) {
			a.insert(i);
			a.insert(n / i);
		}
	}
	for(auto i : a) cout << i << endl;
}