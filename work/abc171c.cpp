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
	ll cnt = 1;
	ll cp = n;
	while(cp > (ll)(pow(26, cnt))){
		cp -= (ll)(pow(26, cnt)), cnt++;
	}
	string ans = "";
	char ch = 'a' - 1;
	ll fix = 0;
	for(ll i = cnt; i >= 1; i--) {
		if(n - (ll)(pow(26, i - 1)) * (n / (ll)(pow(26, i - 1)) < (ll)(pow(26, i - 2) - 1))) fix = 1;
		ans += (char)(ch + n / (ll)(pow(26, i - 1)) - fix);
		n -= (ll)(pow(26, i - 1)) * (n / (ll)(pow(26, i - 1)) - fix);
		fix = 0;
	}
	cout << ans << endl;
}