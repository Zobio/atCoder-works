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
	string s; cin >> s; ll n = s.size();
	vll a, b; //aには文字を、bにはそれに対応する文字数を格納
	rep(i, n) {
		ll cnt = 1, cur = s[i];
		while(i + 1 < n && s[i] == s[i + 1]) cnt++, i++;
		a.push_back(cur); b.push_back(cnt);
	}
	ll ans = 0;
	rep(i, a.size()) {
		if(a[i] == 'J' && a[i + 1] == 'O' && a[i + 2] == 'I' && b[i + 1] <= b[i] && b[i + 1] <= b[i + 2]) chmax(ans, min(min(b[i], b[i + 1]), b[i + 2]));
	}
	cout << ans << endl;
}