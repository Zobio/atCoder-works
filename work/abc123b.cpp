#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	vector<int> a(5);
	for(int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	int ans = 0;
	int top = 0;
	for(int i = 0; i < 5; i++) {
		ans += a[i];
		if(a[i] % 10 != 0)
		ans += 10 - a[i] % 10;
		if(10 - a[i] % 10 > top && a[i] % 10 != 0) top = 10 - a[i] % 10;
	}
	ans -= top;
	cout << ans << endl;
}