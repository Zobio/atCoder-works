#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

ll nCr(ll n, ll r) {
	if(r == 0 || n == r) return 1;
	if(n / 2 < r) r = n - r;
   ll res = 1;
   for (ll i = 1; i <= r; i++) {
       res *= n - r + i;
       res /= i;
   }
   return res;
}

int main() {
	ll a, b, k;
	cin >> a >> b >> k;
	string ans = "";
	ll lim = a + b;
	rep(i, lim) {
		if(a == 0) {ans += 'b'; b--; continue;}
		if(b == 0) {ans += 'a'; a--; continue;}
		if(nCr(a + b - 1, b - 1) < k) ans += 'b', k-= nCr(a + b - 1, b - 1), b--;
		else ans += 'a', a--;
		cout << a + b << " " << k << endl;
	}
	cout << ans << endl;
}