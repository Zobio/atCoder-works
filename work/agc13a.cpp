#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a.at(i);
	if(n == 1) {
		cout << 1 << endl;
		return 0;
	}
	int ans = 0;
	bool sta = true;
	int down = -1;
	for(int i = 0; i < n; i++) {
		if(i == n - 1) {if(down == -1) break; else ans += (bool)down == (bool)(a[i] >= a[i - 1]); break;}
		if(sta) {
			ans++;
			if(a[i] > a[i + 1]) down = 1;
			else if(a[i] < a[i + 1]) down = 0;
			else down = -1;
			sta = false;
			continue;
		}
		if(down == 1 && a[i] < a[i + 1]) sta = true;
		if(down == 0 && a[i] > a[i + 1]) sta = true;
		if(down == -1) {
			if(a[i] > a[i + 1]) down = 1;
			else if(a[i] < a[i + 1]) down = 0;
			else down = -1;
		}
	}
	cout << ans << endl;
}