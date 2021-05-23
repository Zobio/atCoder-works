#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<ll> rest(200, 0);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		rest[a[i] % 200]++;
	}
	ll ans = 0;
	for(int i = 0; i < 200; i++) {
		ans += max((rest[i] * (rest[i] - 1)) / 2, (ll)0);
	}
	cout << ans << endl;
}