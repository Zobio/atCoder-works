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

ll a, n;
ll ans = INF;
vll done(10001000);

ll digit(ll num) {
	ll ret = 0;
	while(num) ret++, num /= 10;
	return ret;
}

void dfs(deque<char> s, ll cnt) {
	ll ss = 0;
	rep(i, s.size()) ss *= 10, ss += s[i] - '0';
	if(ss == n) {chmin(ans, cnt); return;}
	if(digit(ss) > digit(n)) return;
	if(done[ss]) return;
	done[ss] = cnt;
	deque<char> dou;
	for(auto i : to_string(a * ss)) dou.push_back(i);
	s.push_front(s.back()); s.pop_back();
	cnt++;
	dfs(dou, cnt);
	if(ss % 10 != 0) dfs(s, cnt);
}

int main() {
	cin >> a >> n;
	deque<char> s; s.push_back('1');
	dfs(s, 0);
	cout << (ans == INF ? -1 : ans) << endl;
}