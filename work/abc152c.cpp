#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n; cin >> n;
	if(n == 1) {
		cout << 1 << endl; return 0;
	}
	vector<int> p(n);
	rep(i, n) cin >> p.at(i);
	int mi = p[0];
	int ans = 1;
	for(int i = 1; i < n; i++) {
		if(mi < p[i]) {
			
		}else{
			mi = p[i];
			ans++;
		}
	}
	cout << ans << endl;
}