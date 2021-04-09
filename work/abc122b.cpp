#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	string s;
	cin >> s;
	int cnt = 0, ans = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') cnt++;
		else {
			if(cnt > ans) ans = cnt;
			cnt = 0;
		}
	}
	if(cnt > ans) ans = cnt;
	cout << ans << endl;
}