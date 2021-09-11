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
	deque<ll> dq;
	ll mode = 0; //1がソート済み
	priority_queue<ll> pq;
	map<ll, ll> skip;
	vector<ll> ans;
	rep(_, q) {
		ll c; cin >> c;
		if(c == 1) {
			mode = 0;
			ll x; cin >> x;
			dq.push_back(x);
			pq.push(x);
		}
		else if(c == 2) {
			while(skip[pq.top()]) skip[pq.top()]--, pq.pop();
			if(mode == 0) ans.push_back(dq.front()), skip[dq.front()]++;
			else ans.push_back(pq.top()), pq.pop();
		}
		else {
			mode = 1;
		}
		cout << endl;
		arrcout(dq);
		cout << endl;
	}
	rep(i, ans.size()) cout << ans[i] << endl; 
}