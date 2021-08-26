#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

ll n, ans = INF;
vector<ll> m;

void dfs(ll now, ll cnt) {
	auto it = lower_bound(m.begin(), m.end(), now);
	if(*it > now) it--;
	for(auto i = m.begin(); i <= it; i++) {
		if(*i == now) {if(ans < cnt + 1) cout << ans << endl; ans = min(ans, cnt + 1);return;}
		dfs(now - *i, cnt + 1);
	}
}

int main() {
	cin >> n;
	m.push_back(1);
	ll now = 1;
	while(now <= n) now *= 6ll, m.push_back(now);
	now = 1;
	while(now <= n) now *= 9ll, m.push_back(now);
	sort(m.begin(), m.end());
	dfs(n, 0);
	cout << ans << endl;
}