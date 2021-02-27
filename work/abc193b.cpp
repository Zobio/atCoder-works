#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	int p, a, b;
	int ans = MOD;
	for(int i = 0; i < n; i++) {
		cin >> a >> p >> b;
		if(a >= b)
		continue;
		if(p < ans)
		ans = p;
	}
	if(ans != MOD)
	cout << ans << endl;
	else
	cout << -1 << endl;
}