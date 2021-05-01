#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main() {
	string s;
	cin >> s;
	string ans = "";
	bool rev = false;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] != 'R') {
			if(!rev) {
				ans += s[i];
			}else{
				ans.insert(ans.begin(), s[i]);
			}
		}else{
		rev = !rev;
		}
	}
	if(rev) reverse(ans.begin(), ans.end());
	string rep = "";
	for(char c : ans) {
		if(rep.size() && rep.back() == c) rep.pop_back();
		else rep.push_back(c);
	}
	cout << rep << endl;
}