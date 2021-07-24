#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	string tmp;
	cin >> tmp;
	string s = "";
	for(int i = 0; i < tmp.length(); i++) {
		if (tmp[i] == 'c' || tmp[i] == 'h' || tmp[i] == 'o' || tmp[i] == 'k' || tmp[i] == 'u' || tmp[i] == 'd' || tmp[i] == 'a' || tmp[i] == 'i') {
			s += tmp[i];
		}
	}
	if(s.length() < 8) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> a;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == 'c') a.push_back(0);
		if(s[i] == 'h') a.push_back(1);
		if(s[i] == 'o') a.push_back(2);
		if(s[i] == 'k') a.push_back(3);
		if(s[i] == 'u') a.push_back(4);
		if(s[i] == 'd') a.push_back(5);
		if(s[i] == 'a') a.push_back(6);
		if(s[i] == 'i') a.push_back(7);
	}
	int cnt1 = 0, cnt2 = a.size() - 1;
	while(a[cnt1] != 0) cnt1++;
	while(a[cnt2] != 7) cnt2--;
	vector<int> a2;
	for(int i = cnt1; i <= cnt2; i++) {
		a2.push_back(a[i]);
	}
	int len = a2.size();
	vector<vector<int>> rui(len + 1, vector<int>(8));
	for(int i = 0; i < 8; i++) rui[len][i] = 0;
	for(int i = len - 1; i >= 0; i--) {
		for(int j = 0; j < 8; j++) {
			rui[i][j] = a2[i] == j ? rui[i + 1][j] + 1 : rui[i + 1][j];
		}
	}
	vector<int> fis(8);
	fis[0] = 0;
	int now = 1;
	bool done = false;
	for(int i = 1; i <= len - 1; i++) {
		if(a2[i] == now) fis[now] = i, now++;
		if(now == 8) {done = true; break;}
	}
	if(!done) {cout << 0 << endl; return 0;}
	ull ans = 1;
	for(int i = 0; i <= 7; i++) {
		ans = (ans * rui[fis[i]][i]) % MOD;
		cout << i << " " << fis[i] << " " << rui[fis[i]][i] << endl;
	}
	cout << "A" << endl;
	cout << ans << endl;
}