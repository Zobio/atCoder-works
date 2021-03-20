#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int a, b;
	cin >> a >> b;
	int ans = 0;
	for(int i = 0; i < 2; i++) {
		if(a > b)
			ans += a, a--;
		else
			ans += b, b--;
	}
	cout << ans << endl;
}