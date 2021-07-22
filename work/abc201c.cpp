#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	string s;
	cin >> s;
	vector<int> must;
	for(int i = 0; i <= 9; i++) {
		if(s[i] == 'o') must.push_back(i);
	}
	int ans = 0;
	for(int i = 0; i <= 9999; i++) {
		deque<char> pa;
		bool en = false;
		for(char c : to_string(i)) pa.push_back(c);
		while(pa.size() < 4) pa.push_front('0');
		for(int j = 0; j < 4; j++) {
			if(s[pa[j] - '0'] == 'x') {
				en = true;
			}
		}
		for(int j = 0; j <= 9; j++) {
			if(s[j] != 'o') continue;
			bool flag = false;
			for(int k = 0; k <= 4; k++) {
				if(j + '0' == pa[k]) flag = true;
			}
			if(!flag) en = true;
		}
		if(!en) ans++;
	}
	cout << ans << endl;
}