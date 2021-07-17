#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') {
			cout << (i & 1 ? "Aoki" :"Takahashi") << endl;
			return 0;
		}
	}
}