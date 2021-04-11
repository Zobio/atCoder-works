#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	string s;
	cin >> s;
	int end;
	for(int i = s.length() - 1; i >= 0; i--) {
		if(s[i] != '0') {end = i; break;}
	}
	for(int i = 0; i <= end; i++) {
		if(i == end - i) break;
		if(s[i] != s[end - i]) {
			cout << "No" << endl; 
			return 0;
		}
	}
	cout << "Yes" << endl;
}