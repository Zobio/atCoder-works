#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 1LL << 60

int main() {
	int n; cin >> n;
	vector<pair<ll, ll>> xy1;
	vector<pair<ll, ll>> xy2;
	rep(i, n) {
		ll a, b; cin >> a >> b;
		xy1.push_back(make_pair(a, b));
		xy2.push_back(make_pair(b, a));
	}
	sort(xy1.begin(), xy1.end()); sort(xy2.begin(), xy2.end());
	ll ma1 = xy1.back().first - xy1.front().first, ma2 = xy2.back().first - xy2.front().first;
	cout << min(ma1, ma2) << endl;
}