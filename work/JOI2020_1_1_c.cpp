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
	vector<ll> a(n); vector<ll> b(m);
	rep(i, n) cin >> a.at(i); rep(i, m) cin >> b.at(i);
	sort(all(a)); sort(all(b));
	vector<ll> done(1010, false);
	rep(i, n) {
		rep(j, m) {
			if(a[i] == b[j] && !done[a[i]]) cout << a[i] << endl, done[a[i]] = true;
		}
	}
}