#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	vector<int> t(n);
	for(int i = 0; i < n; i++) {
		cin >> s[i] >> t[i];
	}
	long ans = 0;
	bool start = false;
	string title;
	cin >> title;
	for(int j = 0; j < n; j++) {
		if(start) {
			ans += t[j];
		}
		else if(title == s[j]) {
			start = true;
		}
	}
	cout << ans << endl;
}