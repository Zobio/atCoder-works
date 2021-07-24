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
	int now = 0;
	int left, right;
	vector<ll> cho;
	for(int i = 0; i < len; i++) {
		if(now == 0 && a2[i] != 0) continue;
		if(now == 0 && a2[i] == 0) {
			now++;
			left = i;
			continue;
		}
		if(now && now == 7 && a2[i] == 7) {
			cho.push_back(i - left + 1);
			now = 0;
			continue;
		}
		if(a2[i] == now) {
			now++;
			continue;
		}
	}
	ull ans = 0;
	for(int i = 0; i < cho.size(); i++) cho[i] -= 7;
	for(int i = cho.size() - 2; i >= 0; i--) {
		cho[i] = (9 * cho[i] + (cho[i + 1] - 1)) % MOD;
	}
	cout << cho[0] << endl;
}