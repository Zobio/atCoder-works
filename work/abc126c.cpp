#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	double n, k;
	cin >> n >> k;
	double cnt = 1;
	double now, ans = 0;
	for(int i = 1; i <= n; i++) {
		now = i;
		while(now < k){
			cnt /= 2;
			now *= 2;
		}
		ans += cnt / n;
		cnt = 1;
	}
	cout << setprecision(10) << fixed;
	cout << ans << endl;
}