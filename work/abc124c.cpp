#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	string s;
	cin >> s;
	if(s.length() == 1) {
		cout << 0 << endl;
		return 0;
	}
	int right = 0, left = 0;
	string sc = s;
	for(int i = 1; i < s.length(); i++) {
		if(s[i] == s[i - 1]) {
			s[i] = (s[i] == '0' ? '1' : '0');
			left++;
		}
	}
	s = sc;
	for(int i = s.length() - 1; i >= 1; i--) {
		if(s[i - 1] == s[i]) {
			s[i - 1] = (s[i - 1] == '0' ? '1' : '0');
			right++;
		}
	}
	cout << min(right, left) << endl;
}