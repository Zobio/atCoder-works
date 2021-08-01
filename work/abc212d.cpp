#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	std::priority_queue<ll,	vector<ll>, greater<ll>> balls;
	int q;
	cin >> q;
	vector<ll> ans;
	ll pl = 0;
	rep(i, q) {
		int p;
		cin >> p;
		if(p == 1) {
			ll x; cin >> x;
			balls.push(x - pl);
		}
		else if(p == 2){
			ll x; cin >> x;
			pl += x;
		}
		else {
			ans.push_back(balls.top() + pl);
			balls.pop();
		}
	}
	for(auto i : ans) cout << i << endl;
}