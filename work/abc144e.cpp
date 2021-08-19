#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 1LL << 60

int n; ll k;
vector<ll> a;
vector<ll> f;

bool check(ll num) {
	vector<ll> aa = a;
	ll cnt = 0;
	rep(i, n) {
		cnt += max(0ll, aa[i] - (ll)ceil(num / f[i]));
		aa[i] -= max(0ll, aa[i] - (ll)ceil(num / f[i]));
		while(aa[i] * f[i] > num) {
			cnt++; aa[i]--;
		}
	}
	return cnt <= k;
}

int main() {
	cin >> n; cin >> k;; 
	a.resize(n); rep(i, n) cin >> a.at(i); sort(a.begin(), a.end());
	f.resize(n); rep(i, n) cin >> f.at(i); sort(f.rbegin(), f.rend());
	ll ng = -1, ok = INF;
	while(ok - ng > 1) {
		ll mid = (ok + ng) / 2;
		if(check(mid)) ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
}