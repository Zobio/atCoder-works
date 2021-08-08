#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(a) cout << a << endl

int main() {
	std::priority_queue<ll, vector<ll>, greater<ll>> balls;
	int q;
	cin >> q;
	vector<ll> ans;
	ll pl = 0;
	rep(i, q) {
		ll mode, num;
		cin >> mode;
		if(mode == 1) {
			cin >> num;
			balls.push(num - pl);
		}
		else if(mode == 2) {
			cin >> num;
			pl += num;
		}
		else {
			ans.push_back(balls.top() + pl);
			balls.pop();
		}
	}
	for(auto i : ans) cout << i << endl;
}