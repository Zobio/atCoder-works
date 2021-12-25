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
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	string s; cin >> s;
	ll len = s.size();
	vll rui(len + 2);
	rep(i, len) rui[i + 1] = rui[i] + s[i] - '0';
	reverse(all(rui));rui.pop_back(); reverse(all(rui)); rui.push_back(0); reverse(all(rui));
	string ans = "";
	rep(i, len) {
		rui[i + 1] += i ? rui[i] / 10 : 0;
		ans += '0' + rui[i + 1] % 10;
	}
	if(rui[len + 1]) ans += '0' + rui[len + 1] % 10;
	reverse(all(ans));
	cout << ans << endl;
}