#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] != s[s.length() - i - 1]) {
			s[s.length() - i - 1] = s[i];
			ans++;
		}
	}
	cout << ans << endl;
}