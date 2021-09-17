#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	ll n; cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a.at(i);
	ll ma = -1, pl = -1;
	rep(i, n) {if(a[i] > ma) ma = a[i], pl = i;}
	ll ans = 0;
	rep(i, pl) ans += a[i]; cout << ans << endl;
	ans = 0;
	for(ll i = (pl+1); i < n;i++) ans += a.at(i); cout << ans << endl;
}