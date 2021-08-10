#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m;
	cin >> n >> m;
	vector<bool> like(m, true);
	rep(i, n) {
		int k; cin >> k;
		vector<int> a(k);
		rep(j, k) cin >> a.at(j), a.at(j)--;
		sort(a.begin(), a.end());
		int now = 0;
		for(int j = 0; j < m; j++) {
			if(a[now] == j) {
				if (now != k - 1) now++;
			}else{
				like[j] = false;
			}
		}
	}
	int ans = 0;
	rep(i, m) if(like[i]) ans++;
	cout << ans << endl;
}