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

ll n, x;
vll l;
vvll a;
ll ans = 0;

void dfs(ll fukuro, ll num, ll state) {
	if(log10(state) + log10(a[fukuro][num]) > 18.0) return;
	state *= a[fukuro][num];
	if(state > 1000000000000000000ll) return;
	if(fukuro == n - 1) {ans += state == x; return;}//終わり
	rep(i, l.at(fukuro + 1)) dfs(fukuro + 1, i, state);
}

int main() {
	cin >> n >> x;
	l.resize(n); a.resize(n);
	rep(i, n) {
		cin >> l[i];
		rep(j, l[i]) {ll tmp; cin >> tmp; a[i].push_back(tmp);}
	}
	rep(i, n) sort(all(a[i]));
	rep(i, l[0]) dfs(0, i, 1ll);
	cout << ans << endl;
}