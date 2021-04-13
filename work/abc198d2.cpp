#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

vector<string> s(3), ss(3);
vector<bool> word(26, false), yet(10, false);
vector<int> n(26);

void dfs(int x) {
	if(x == 26) {
		ss[0] = ss[1] = ss[2] = "";
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < s[i].size(); j++) {
				ss[i] += n[s[i][j] - 'a'] + '0';
			}
		}
		if(ss[0][0] == '0' || ss[1][0] == '0' || ss[2][0] == '0') return;
		if(stoll(ss[0]) + stoll(ss[1]) == stoll(ss[2])) {
			cout << ss[0] << endl << ss[1] << endl << ss[2] << endl;
			exit(0);
		}
		return;
	}
	if(!word[x]){dfs(x+1);return;}
	for(int i = 0; i < 10; i++) {
		if(yet[i]) continue;
		n[x] = i;
		yet[i] = true;
		dfs(x + 1);
		yet[i] = false;
	}
}

int main() {
	cin >> s[0] >> s[1] >> s[2];
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < s[i].size(); j++) {
			word[s[i][j] - 'a'] = true;
		}
	}
	for(int i = 0; i < 26; i++) {
		if(word[i]) {
			dfs(i);
			break;
		}
	}
	puts("UNSOLVABLE");
	return 0;
}