#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int ans = MOD;
	int n; string s;
	cin >> n >> s;
	int cnt = 0;
	for(int i = 1; i < n; i++) {
		if(s[i] == 'E') cnt++;
	}
	ans = cnt;
	for(int i = 1; i < n; i++) {
		if(s[i - 1] == 'W') cnt++;
		if(s[i] == 'E') cnt--;
		ans = min(ans, cnt);
	}
	cout << ans << endl;
}