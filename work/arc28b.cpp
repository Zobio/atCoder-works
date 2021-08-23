#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	ll n, k; cin >> n >> k;
	priority_queue<pair<ll, ll>> x; 
	for(ll i = 0; i < n; i++) {
		ll tmp; cin >> tmp;
		if(x.size() < k) x.push(make_pair(tmp, i + 1));
		else if(tmp < x.top().first) x.push(make_pair(tmp, i + 1));
		if(x.size() == k + 1) x.pop();
		if(i + 1 < k) continue;
		cout << x.top().second << endl;
	}
}