#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n, p, q; cin >> n >> p >> q;
	vll a(n); rep(i, n) cin >> a.at(i), a[i] %= p;
	sort(all(a));
	#define rep(i, j, n) for (long long i = j; i < n; i++)
	ll ans = 0;
	rep(i, 0, n) rep(j, i + 1, n) rep(k, j + 1, n) rep(l, k + 1, n) rep(m, l + 1, n) {
		if(a[i] * a[j] % p * a[k] % p * a[l] % p * a[m] % p == q) ans++;
	}
	cout << ans << endl;
}