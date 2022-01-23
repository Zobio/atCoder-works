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

ll n;
ll ans = 0;
vvll a;

void dfs(ll cnt, ll pt, vll done) {
	if(cnt == n) {chmax(ans, pt); return;}
	rep(i, n) {
		for(ll j = i + 1; j < n; j++) {
			if(done[i] || done[j]) continue;
			done[i] = done[j] = true;
			dfs(cnt + 2, (pt ^ a[i][j]), done);
			done[i] = done[j] = false;
		}
		if(!done[i]) return;
	}
}

int main() {
	cin >> n; n *= 2;
	a.resize(n);
	rep(i, n) {
		rep(j, i + 1) a[i].push_back(0);
		rep(j, n - i - 1) {
			ll p; cin >> p; a[i].push_back(p);
		}
	}
	vll done(n);
	dfs(0, 0, done);
	cout << ans << endl;
}