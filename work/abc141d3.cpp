#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(a) cout << a << endl;
#define co(a, b) cout << a << " " << b << endl

int main() {
	int n, m;
	cin >> n >> m;
	priority_queue<int> pq;
	rep(i, n) {
		int a;
		cin >> a;
		pq.push(a);
	}
	rep(i, m) {
		int a = pq.top();
		pq.pop();
		a /= 2;
		pq.push(a);
	}
	ll ans = 0;
	rep(i, n) ans += pq.top(), pq.pop();
	cout << ans << endl;
}