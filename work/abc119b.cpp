#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	double ans = 0;
	for(int i = 0; i < n; i++) {
		double a; string b;
		cin >> a >> b;
		if(b == "BTC") {
			a *= 380000;
		}
		ans += a;
	}
	cout << ans << endl;
}