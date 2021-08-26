#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	ll n; cin >> n;
	vector<ll> m; m.push_back(1);
	ll now = 1;
	while(now <= n) now *= 6ll, m.push_back(now);
	now = 1;
	while(now <= n) now *= 9ll, m.push_back(now);
	sort(m.begin(), m.end());
	vector<ll> dp(n + 1, INF); dp[0] = 0;
	rep(i, n) {
		auto it = lower_bound(m.begin(), m.end(), i+1);
		if(*it == i+1) {dp[i+1] = 1;continue;}
		for(auto a = m.begin(); a < it; a++) {
			dp[i+1] = min(dp[i+1], dp[(i + 1) - *a] + 1);
		}
	}
	cout << dp[n] << endl;
}