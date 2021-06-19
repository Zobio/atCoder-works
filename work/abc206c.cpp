#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ll n;
	cin >> n;
	map<ll, ll> num;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num[a - 1]++;
	}
	ll ans = n * (n - 1) / 2;
	for (auto it = num.begin(); it != num.end(); ++it) {
		ans -= (ll)((it -> second) * (it -> second - 1) / 2);
	}
		cout << ans << endl;
}