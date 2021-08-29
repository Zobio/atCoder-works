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
	ll n, m; cin >> n >> m;
	queue<ll> que;
	vector<queue<ll>> a(m);
	vector<vector<ll>> memo(n);
	rep(i, n) {
		ll k; cin >> k;
		rep(j, k) {
			ll tmp; cin >> tmp; tmp--;
			a[i].push(tmp);
		}
		memo[a[i].front()].push_back(i);
	}
	rep(i, n) if(memo[i].size() == 2) que.push(i);
	while(!que.empty()) {
		ll now = que.front(); que.pop();
		for(auto p: memo[now]){
			a[p].pop();
			if(!a[p].empty()){
				memo[a[p].front()].push_back(p);
				if(memo[a[p].front()].size() == 2){
					que.push(a[p].front());
				}
			}
		}
	}
	for(auto p: a){
		if(!p.empty()){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}