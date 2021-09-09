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
	ll l, q; cin >> l>> q;
	set<ll> cut;
	cut.insert(0);
	rep(_, q) {
		ll c, x; cin >> c >> x;
		if(c == 1) {
			cut.insert(x); continue;
		}
		auto it = cut.lower_bound(x);
		if(it == cut.end()) cout << l - *--it << endl; 
		else cout << *it - *--it << endl;
	}
}