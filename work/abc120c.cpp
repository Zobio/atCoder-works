#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	string s;
	cin >> s;
	int ans0 = 0, ans1 = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '0') ans0++;
		else ans1++;
	}
	cout << min(ans0, ans1) * 2 << endl;
}