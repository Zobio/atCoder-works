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
	ll ans = 1;
	rep(i, n) {
		for(ll j = i + 1; j < n; j++) {
			ll now = i, num = a[i];
			while(a[now] >= num && now <= j) num = a[now], now++;
			ans = max(ans, now - i);
		}
	}
	cout << ans << endl;
}