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
	ll k; string a, b; cin >> k >> a >> b;
	ll ans1 = 0, ans2 = 0;
	rep(i, a.size()) ans1 *= k, ans1 += a[i] - '0';
	rep(i, b.size()) ans2 *= k, ans2 += b[i] - '0';
	cout << ans1 * ans2 << endl;
}