#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	string s;
	cin >> s;
	if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3] && s[3] == s[0]) {
		cout << "Weak" << endl;
		return 0;
	}
	bool flag = false;
	if(!((s[0] == '9' && s[1] == '0') || (s[1] - s[0] == 1))) flag = true;
	for(int i = 1; i < 4; i++) {
		if (!((s[i - 1] == '9' && s[i] == '0') || (s[i] - s[i - 1] == 1))) flag = true;
	}
	if(!flag) cout << "Weak" << endl;
	else cout << "Strong" << endl;
}