#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(i) cout << i << endl

int main() {
	int n; ll w;
	cin >> n >> w;
	vector<ll> simu(210000);
	rep(i, n) {
		int a, b; ll c;
		cin >> a >> b >> c;
		simu[a] += c;
		simu[b] -= c;
	}
	ll now = 0;
	rep(i, 200001) {
		now += simu[i];
		if(now > w) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}