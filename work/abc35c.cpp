#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(i) cout << i << endl

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> o(n, 0);
	rep(i, q) {
		int a, b;
		cin >> a >> b;
		a--;
		o[a]++; o[b]++;
	}
	bool status = false;
	rep(i, n) {
		if(o[i] & 1) status = !status;
		cout << (status ? 1 : 0);
	}
	cout << endl;
}