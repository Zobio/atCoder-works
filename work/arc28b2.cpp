#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	ll n, k; cin >> n >> k;
	vector<ll> ans;
	map<ll, ll> mp;
	rep(i, n) {
		ll tmp; cin >> tmp;
		mp[tmp] = i + 1;
		ans.insert(lower_bound(ans.begin(), ans.end(), tmp), tmp);
		if(ans.size() < k) continue;
		cout << mp[ans[k - 1]] << endl;
	}
}