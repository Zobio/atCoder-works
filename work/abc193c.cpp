#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ll n, now;
	cin >> n;
	list<ll> ex;
	for(ll i = 2; i * i <= n; i++) {
		now = i * i;
		while(now <= n) {
			ex.push_back(now);
			now *= i;
		}
	}
	ex.sort();
	ex.unique();
	cout << n - ex.size() << endl;
}