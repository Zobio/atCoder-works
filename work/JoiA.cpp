#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans = 1e9;
	int n;
	cin >> n;
	vector<string> s(n);
	vector<string> t(n);
	vector<string> tmp(n);
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	int count = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(s[j][k] != t[j][k]) {
					count++;
				}
			}
		}
		ans = min(ans, count);
		for (int j = 0; j < n; j++) {
			tmp[j] = s[j];
		}
	for(int j = 0; j < n; j++) {
		for(int k = 0; k < n; k++) {
			s[j][k] = tmp[k][n - 1 - j];
		}
	}
	count = i % 2 ? 2 : 1;
	}
	cout << ans << endl;
}