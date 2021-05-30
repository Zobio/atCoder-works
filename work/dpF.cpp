#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	int slen = s.length(), tlen = t.length();
	vector<bool> yetS(slen, true);
	vector<bool> yetT(tlen, true);
	string ans = "";
	for(int i = 0; i < slen; i++) {
		for(int j = 0; j < tlen; j++) {
			if(!yetS[i] || !yetT[j]) continue;
			if(s[i] == t[j]) {
				cout << i << " " << j << " " << s[i] << endl;
				ans += s[i];
				yetS[i] = false;
				yetT[j] = false;
			}
		}
	}
	cout << ans << endl;
}