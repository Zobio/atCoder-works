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
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n, m; string s;
	cin >> n >> m >> s;
	vll a(m); rep(i, m) a[i] = s[i] == 'I' ? 1 : 0;
	vll rui(m + 1); rep(i, m) rui[i + 1] = rui[i] + a[i];
	ll len = n * 2 + 1, ans = 0;
	arrcout(rui);
	for(ll i = 0; i < m - len + 1; i++) {
		if(a[i + 1] == 1 && rui[i + len] - rui[i] == n) cout << i+1 << endl, ans++;
		cout << i + len << " " << i << " " << rui[i + len] - rui[i] << endl;
	}
	cout << ans << endl;
}