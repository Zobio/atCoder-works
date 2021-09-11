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
	ll q; cin >> q;
	deque<ll> d;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	vector<ll> ans;
	rep(_, q) {
		ll m; cin >> m;
		if(m == 1) {
			ll x; cin >> x;
			d.push_back(x);
		}
		else if(m == 2) {
			if(pq.empty()) ans.push_back(d.front()), d.pop_front();
			else ans.push_back(pq.top()), pq.pop(), d.pop_front();
		}
		else {
			while(!pq.empty()) pq.pop();
			for(auto a : d) pq.push(a);
		}
		arrcout(d);
	}
	for(auto a : ans) cout << a << endl;
}