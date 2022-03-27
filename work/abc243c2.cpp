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

struct lim {
	ll left_max;
	ll right_min;
};

int main() {
	ll n; cin >> n;
	vpll xy(n);
	rep(i, n) cin >> xy[i].first >> xy[i].second;
	string s; cin >> s;
	map<ll, lim> mp;
	rep(i, n) {
		if(mp.find(xy[i].second) == mp.end()) {
			if(s[i] == 'L') mp[xy[i].second] = {xy[i].first, INF};
			else mp[xy[i].second] = {-INF, xy[i].first};
		}else{
			if(s[i] == 'L') chmax(mp[xy[i].second].left_max, xy[i].first);
			else chmin(mp[xy[i].second].right_min, xy[i].first);
		}
	}
	for(auto au : mp) {
		if(au.second.left_max >= au.second.right_min) {cout << "Yes" << endl; return 0;}
	}
	cout << "No" << endl;
}