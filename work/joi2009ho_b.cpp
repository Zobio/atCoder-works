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
	ll d, n, m; cin >> d >> n >> m;
	vll s(n); s[0] = 0; vll k(m);
	rep(i, n - 1) cin >> s[i]; rep(i, m) cin >> k[i];
	sort(all(s)); sort(all(k));
	ll ans = 0;
	rep(i, m) {
		vll::iterator it1 = lower_bound(all(s), k[i]);
		vll::iterator it2;
		if(it1 == s.end()) it1 = s.begin();
		if(it1 != s.begin()) it2 = lower_bound(all(s), k[i]) - 1;
		else it2 = s.end() - 1;

		if(it1 - it2 >= 0) ans += min(k[i] - *it2, *it1 - k[i]);
		else {
			ll pl = INF;
			if(*it1 - k[i] >= 0) chmin(pl, *it1 - k[i]);
			else chmin(pl, d - k[i] + *it1);
			if(k[i] - *it2 >= 0) chmin(pl, k[i] - *it2);
			else chmin(pl, d - *it2 + k[i]);
			ans += pl;
		}
	}
	cout << ans << endl;
}