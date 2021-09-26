#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	ll n; cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	rep(i, n) cin >> a.at(i), sum += a[i];
	ll x; cin >> x;
	ll ans = (x / sum) * n;
	ll now = sum * (x / sum);
	rep(i, n) {
		ans++; now += a[i]; 
		if(now > x) {cout << ans << endl; return 0;} 
	}
	cout << ans << endl; 
}