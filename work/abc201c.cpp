#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	string s;
	cin >> s;
	int ans = 0;
	for(int a = 0; a <= 9; a++) {
		for (int b = 0; b <= 9; b++) {
			for(int c = 0; c <= 9; c++) {
				for(int d = 0; d <= 9; d++) {
					if (s[a] != 'x' && s[b] != 'x' && s[c] != 'x' && s[d] != 'x') ans++;
				}
			}
		}
	}
	cout << ans << endl;
}