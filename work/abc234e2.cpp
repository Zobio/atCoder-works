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
#define INF LLONG_MAX
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

bool check(string s) {
	ll d = s[1] - s[0];
	rep(i, s.size() - 1) {
		if(s[i + 1] - s[i] != d) return false;
	}
	return true;
}

int main() {
	string s; cin >> s;
	if(s.size() <= 2) {cout << s << endl; return 0;} //コーナー
	ll len = s.length();
	ll ans = LLONG_MAX;
	reps(i, 9) rep(j, 10) {
		if(stoll(to_string(i) + to_string(j)) < stoll(to_string(s[0] - '0') + to_string(s[1] - '0'))) continue;
		string t = ""; ll d = j - i;
		t.push_back('0' + i); t.push_back('0' + j);
		rep(i, len - 2) t.push_back((t.back() - '0' + d + 10) % 10 + '0');
		if(check(t) && stoll(t) >= stoll(s)) chmin(ans, stoll(t));
	}
	cout << ans << endl;
}