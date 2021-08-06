#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define ce(i) cout << i << endl

int main()
{
	ll n;
	cin >> n;
	ll cnt = 1;
	ll cp = n;
	vector<ll> rui; rui.push_back(1);
	ll now = 0;
	while((ll)(pow(26, now)) <= (ll)1000000000000001) {
		rui.push_back(rui[now] + (ll)(pow(26, now + 1)));
		now++;
	}
	while (cp > (ll)(pow(26, cnt)))
		cp -= (ll)(pow(26, cnt)), cnt++;
	string ans = "";
	char ch = 'a' - 1;
	for (ll i = cnt; i >= 1; i--) {
		ll fix = 0;
		if (i != 1)if((n - rui[i - 2]) % (ll)(pow(26, i - 1)) * (n / (ll)(pow(26, i - 1))) < rui[i - 2]) fix = 1;
		cout << (n - rui[i - 2]) / (ll)(pow(26, i - 1)) - fix << " " << (n - rui[i - 2]) % (ll)(pow(26, i - 1)) * ((n - rui[i - 2]) / (ll)(pow(26, i - 1))) << " " << rui[i - 2] << endl;
		ans += (char)(ch + (n - rui[i - 2]) / (ll)(pow(26, i - 1)) - fix);
		n -= (ll)(pow(26, i - 1)) * ((n - rui[i - 2]) / (ll)(pow(26, i - 1)) - fix);
	}
	cout << ans << endl;
}