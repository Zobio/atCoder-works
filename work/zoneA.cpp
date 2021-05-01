#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main() {
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < s.length() - 3; i++) {
		if(s[i] == 'Z' && s[i + 1] == 'O' && s[i + 2] == 'N' && s[i + 3] == 'e') ans++;
	}
	cout << ans << endl;
}