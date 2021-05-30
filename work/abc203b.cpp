#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			ans += i * 100 + j;
		}
	}
	cout << ans << endl;
}