#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	int slen = s.length(), tlen = t.length();
	vector<bool> yet(tlen, true);
	int len = 0;
	for(int i = 0; i < slen; i++) {
		for(int j = 0; j < tlen && yet[j]; j++) {
			if(s[i] == t[j]) {
				len++;
				yet[j] = false;
			}
		}
	}
	cout << len << endl;
}