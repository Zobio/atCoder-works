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
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n; cin >> n;
	string s; cin >> s;
	vector<deque<ll>> ans;
	deque<ll> matubi;
	ll now = s[0];
	deque<ll> cur;
	rep(i, n) {
		if(s[i] != now) {
			ans.push_back(cur);
			cur.clear();
			cur.push_back(i + 1);
			now = s[i];
			continue;
		}
		if(now == 'L') {
			cur.push_front(i + 1);
		}else{
			cur.push_back(i + 1);
		}
	}
	if(!cur.empty()) ans.push_back(cur);
	if(s[0] == 'L') {
		for(ll i = 0; i < ans.size(); i += 2) {
			for(auto au : ans[i]) cout << au << " "; cout << endl;
		}
		for(ll i = ans.size() - !(ans.size() & 1); i >= 0; i -= 2) {
			for(auto au : ans[i]) cout << au << " "; cout << endl;
		}
		cout << 0 << endl;
	}
}