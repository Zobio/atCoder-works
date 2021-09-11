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
	vector<int> ans;
	while(n) {
		ll r = n % 2;
		if(r < 0) r += 2;
		n = (n - r) / -2;
		ans.push_back(r);
	}
	if(ans.empty()) ans.push_back(0);
	reverse(ans.begin(), ans.end());
	rep(i, ans.size()) cout << ans[i]; cout << endl;
}