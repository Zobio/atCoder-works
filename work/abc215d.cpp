#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 1LL << 60

long long gcd(long long a, long long b) {
	// a<bのときa % b == aなので結局gcd(b, a)に帰結する。
	if (a % b == 0) {
		return b;
	}else{
		return gcd(b, a % b);
	}
}

int main() {
	ll n, m; cin >> n >> m;
	vector<bool> done(m + 1, false);
	vector<ll> a(n); rep(i, n) cin >> a.at(i);
	rep(i, n) {
		if(a[i] <= m) done[a[i]] = true;
		for(int j = 1; j <= min(m, (ll)(sqrt(a[i]) + 1LL)); j++) {
			if(gcd(a[i], j) != 1 && j <= m) done[j] = true, done[a[i] / j] = true;
		}
	}
	for(int i = 2; i <= m; i++) {
		if(done[i]) {
			ll tmp = i * 2ll;
			while(tmp <= m) {
				done[tmp] = true;
				tmp += i;
			}
		}
	}
	done[1] = false;
	vector<ll> ans;
	for(ll i = 1; i <= m; i++) {
		if(!done[i]) ans.push_back(i);
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) cout << ans[i] << endl;
}