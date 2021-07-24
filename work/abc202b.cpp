#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '6') s[i] = '9'; 
		else if(s[i] == '9') s[i] = '6'; 
	}
	reverse(s.begin(), s.end());
	cout << s << endl;
}