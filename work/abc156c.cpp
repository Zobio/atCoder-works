#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<int> x(n);
	for(int i = 0; i < n; i++) cin >> x[i], x[i]--;
	ll ans = MOD;
	for(int i = 0; i < 100; i++) {
		ll sum = 0;
		for(int j = 0; j < n; j++) {
			sum += abs(i - x[j]) * abs(i - x[j]);
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
}