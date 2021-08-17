#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m, x;
	cin >> n >> m >> x;
	vector<ll> c(n);
	vector<vector<ll>> book(n, vector<ll>(m));
	rep(i, n) {cin >> c[i]; rep(j, m) cin >> book[i][j];}
	ll ans = 1e9;
	for(int bits = 0; bits < (int)(pow(2, n)); bits++) {
		vector<ll> sk(m, 0); ll price = 0;
		for(int i = 0; i < n; i++) {
			if(bits & (1 << i)) {price += c[i]; rep(j, m) sk[j] += book[i][j];}
		}
		bool flag = true;
		rep(i, m) if(sk[i] < x) flag = false;
		if(!flag) continue;
		ans = min(ans, price);
	}
	cout << (ans == 1e9 ? -1 : ans) << endl;
}