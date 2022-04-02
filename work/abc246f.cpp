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
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

template<typename T>
T mpow(T a, T n, T m) {
	/*a^n % mを返す
	(例)
	pow(2, 10, 1000) --> 24
	計算量はlog(n)
	*/
	T ret = 1;
	while(n > 0) {
		if (n & 1) ret = ret * a % m;
		a = a % m * a % m;
		n >>= 1;
	}
	return ret;
}

ll n, l, ans = 0;

vector<string> f(vector<string> s) {
	rep(i, s.size()) ans = (ans - mpow((ll)s[i].size(), l, MOD) + MOD) % MOD;
	vector<string> ss;
	rep(i, s.size()) for(ll j = i + 1; j < s.size(); j++) {
		if(s[i] == s[j]) continue;
		string t;
		rep(p, 26) {
			if(find(all(s[i]), 'a' + p) != s[i].end() && find(all(s[j]), 'a' + p) != s[j].end())  t.push_back('a' + p);
		}
		if(t.size()) ss.push_back(t);
	}
	return ss;
}

int main() {
	cin >> n >> l;
	vector<string> s(n); rep(i, n) cin >> s[i];
	rep(i, n) ans = (ans + mpow((ll)s[i].size(), l, MOD)) % MOD;
	vector<string> ss;
	map<string, ll> cnt;
	rep(i, n) for(ll j = i + 1; j < n; j++) {
		string t;
		rep(p, 26) {
			if(find(all(s[i]), 'a' + p) != s[i].end() && find(all(s[j]), 'a' + p) != s[j].end())  t.push_back('a' + p);
		}
		if(t.size()) cnt[t]++;
	}
	for(auto au : cnt) {
		ans = (ans - mpow((ll)au.first.size(), au.second, MOD) + MOD) % MOD;
	}
	cout << ans << endl;
}