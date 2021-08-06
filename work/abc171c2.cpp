#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define ce(i) cout << i << endl

int main() {
	ll n;
	cin >> n;
	string ans = "";
	while(n) {
		n--;
		ans += (char)('a' + n % 26);
		n /= 26;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}