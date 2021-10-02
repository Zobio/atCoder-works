#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 1000000007LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n; cin >> n;
	vector<pair<ll, ll>> event;
	rep(i, n) {
		ll a, b; cin >> a >> b; a--;
		event.emplace_back(a, 1);
		event.emplace_back(a + b, -1);
	}
	sort(all(event));
	vll ans(n + 1);
	ll old = 0, pt = 0;
	for(auto e : event) {
		ll now = e.first;
		ans[pt] += now - old;
		pt += e.second;
		old = now;
	}
	rep(i, n) cout << (i ? " " : "") << ans[i + 1];
	cout << endl;
}