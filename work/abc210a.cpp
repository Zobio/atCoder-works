#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, a, x, y;
	cin >> n >> a >> x >> y;
	if(n <= a) cout << (ull)(n * x) << endl;
	else{
		ull ans = 0;
		ans += (ull)(a * x);
		ans += (ull)((n - a) * y);
		cout << ans << endl;
	}
}