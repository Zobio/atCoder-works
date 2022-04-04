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

ll score(string s) {
	vll ret(10);
	iota(all(ret), 0);
	for(auto au : s) ret[au - '0'] *= 10;
	return accumulate(all(ret), 0ll);
}
int main() {
	setcout(15);
	ll k; cin >> k;
	string s, t; cin >> s >> t;
	s.pop_back(); t.pop_back();
	vll cnt(10, k);
	for(auto au : s + t) cnt[au - '0']--;
	ll po = 0;
	reps(i, 9) reps(j, 9) {
		s.push_back('0' + i); t.push_back('0' + j);
		if (score(s) > score(t)) po += cnt[i] * (cnt[j] - (i == j));
		s.pop_back(); t.pop_back();
	}
	ll al = 9 * k - 8;
	cout << (ld)po / al / (al - 1) << endl;
}