#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<ll> dp1(n + 1);
	vector<ll> dp2(n + 1);
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if(a == 1) {
			dp1[i + 1] += dp1[i] + b;
			dp2[i + 1] += dp2[i];
		}else{
			dp1[i + 1] += dp1[i];
			dp2[i + 1] += dp2[i] + b;
		}
	}
	int q; cin >> q;
	for(int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		cout << dp1[b] - dp1[a - 1] << " " << dp2[b] - dp2[a - 1] << endl;
	}
}