#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	vector<bool> a(4, false);
	for(int i = 0; i < 4; i++) {
		string s;
		cin >> s;
		if(s == "H") a[0] = true;
		else if(s == "2B") a[1] = true;
		else if (s == "3B")
			a[2] = true;
		else a[3] = true;
	}
	if(a[0] && a[1] && a[2] && a[3]) cout << "Yes" << endl;
	else cout << "No" << endl;
}