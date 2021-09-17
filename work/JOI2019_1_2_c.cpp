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
	ll n, m; cin >> n >> m;
	vector<ll> a(n);
	rep(i, n) cin >> a.at(i);
	vector<ll> b(m + 1);
	rep(i, n) b[a[i]]++;
	ll ans = 0;
	rep(i, m) ans = max(ans, b[i + 1]);
	cout << ans << endl;
}