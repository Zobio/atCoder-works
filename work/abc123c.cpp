#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ll n;
	vector<ll> a(5);
	cin >> n;
	ll mini = 1000000000000001;
	for(int i = 0; i < 5; i++) {
		cin >> a[i];
		if(a[i] < mini) mini = a[i];
	}
	ll ans = 5;
	ans += n / mini;
	if(n % mini != 0) ans++;
	ans--;
	cout << ans << endl;
}