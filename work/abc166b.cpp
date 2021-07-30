#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, k;
	cin >> n >> k;
	map<int, int> m;
	rep(i, k) {
		int d;
		cin >> d;
		rep(j, d) {
			int tmp;
			cin >> tmp;
			m[--tmp]++;
		}
	}
	int ans = 0;
	rep(i, n) {
		if(m[i] == 0) ans++;
	}
	cout << ans << endl;
}