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

string s;
ll q;

ll find(ll t, ll k) { //t回、k文字目
	if(t == 0) return s[k] - 'A';
	if(k == 0) return (s[0] - 'A' + t) % 3;
	
	if(k % 2 == 0) return (find(t - 1, k / 2) + 1) % 3;
	else return (find(t - 1, k / 2) + 2) % 3;
}

int main() {
	cin >> s;
	cin >> q;
	vpll qs(q); rep(i, q) cin >> qs[i].first >> qs[i].second, qs[i].second--;
	string ans;
	rep(i, q) {
		ll t = qs[i].first, k = qs[i].second;
		ans.push_back('A' + find(t, k));
	}
	for(auto au : ans) cout << au << endl;
}