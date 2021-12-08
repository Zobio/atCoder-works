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
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n; cin >> n;
	string s; cin >> s;
	vector<string> t(n); rep(i, n) cin >> t[i];
	vector<bool> ok(n);
	ll len = s.size();
	rep(i, n) {
		for(ll j = 1; j <= (t[i].size() - 1) / (len - 1); j++/*間隔*/) {
			for(ll k = 0; k + j * (len - 1) < t[i].size(); k++) {
				bool fl = true; ll cnt = 0;
				for(ll l = k; l < t[i].size() && cnt < len; l += j) {
					if(t.at(i).at(l) != s[cnt]) fl = false;
					cnt++;
				}
				if(fl) ok[i] = true;
			}
		}
	}
	ll ans = 0; rep(i, n) ans += ok[i];
	cout << ans << endl;
}