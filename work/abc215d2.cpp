#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 1LL << 60

int main() {
	ll n, m; cin >> n >> m;
	vector<ll> a(n); rep(i, n) cin >> a.at(i);
	vector<bool> ans(1000010, true);
	rep(i, n) {
		for(int j = 1; j <= min(m, (ll)(sqrt(a[i]) + 1)); j++) {
			if(a[i] % j == 0) ans[j] = ans[a[i] / j] = false;
		}
	}
	for(ll i = 2; i <= m / 2 + 1; i++) {
		if(!ans[i]) {
			for(ll j = i * 2; j <= m; j += i) ans[j] = false;
		}
	}
	ans[1] = true; //例外
	vector<ll> rep;
	ll cnt = 0; for(int i = 1; i <= m; i++) if(ans[i])cnt++, rep.push_back(i);
	cout << cnt << endl;
	rep(i, rep.size()) cout << rep[i] << endl;
}