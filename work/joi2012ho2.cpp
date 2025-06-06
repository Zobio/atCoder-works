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
	ll n, m; cin >> n >> m; vll a(n), b(m); rep(i, n) cin >> a[i]; rep(i, m) cin >> b[i];
	vector<deque<ll>> c(10010); //c[i] ... a[i] == b[j]であるすべてのj
	rep(i, m) rep(j, n) if(b[i] == a[j]) c[b[i]].push_back(j);
	ll ans = 0;
	rep(i, m) {rep(j, c[i].size()) cout << c[i][j] << " "; cout << endl;}
	rep(i, m - 1) {
		vll num(10010);
		ll cnt = 1;
		while(i < m - 1 && c[b[i + 1]][num[b[i + 1]]] > c[b[i]][num[b[i]]]) cnt++, i++, num[b[i]]++;
		chmax(ans, cnt);
		while(i < m - 1 && c[b[i + 1]].front() > c[b[i]].front()) i++;
	}
	cout << ans << endl;
}