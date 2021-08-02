#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	string s;
	cin >> s;
	if(s[0] == s[1] && s[1] == s[2] && s[2] == s[0]) {
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}
}