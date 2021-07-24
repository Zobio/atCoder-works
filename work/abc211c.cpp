#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	string s;
	cin >> s;
	vector<map<char, ull>> rui(s.length() - 1);
		rui[s.length()]['h'] = 0; rui[s.length()]['o'] = 0; rui[s.length()]['k'] = 0; rui[s.length()]['u'] = 0; rui[s.length()]['d'] = 0; rui[s.length()]['a'] = 0; rui[s.length()]['i'] = 0;
	for(int i = s.length() - 1; i >= 0; i--) {
		rui[s.length() - 1]['h'] = s[i] == 'h' ? rui[i + 1]['h'] : rui[i + 1]['h'] + 1;
		rui[s.length() - 1]['o'] = s[i] == 'o' ? rui[i + 1]['o'] : rui[i + 1]['o'] + 1;
		rui[s.length() - 1]['k'] = s[i] == 'k' ? rui[i + 1]['k'] : rui[i + 1]['k'] + 1;
		rui[s.length() - 1]['u'] = s[i] == 'u' ? rui[i + 1]['u'] : rui[i + 1]['u'] + 1;
		rui[s.length() - 1]['d'] = s[i] == 'd' ? rui[i + 1]['d'] : rui[i + 1]['d'] + 1;
		rui[s.length() - 1]['a'] = s[i] == 'a' ? rui[i + 1]['a'] : rui[i + 1]['a'] + 1;
		rui[s.length() - 1]['i'] = s[i] == 'i' ? rui[i + 1]['i'] : rui[i + 1]['i'] + 1;
	}
	ull ans = 0;
	for(int i = 0; i < s.length() - 1; i++) {
		if(s[i] != 'c') continue;
		ans = ans * 
	}
}