#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int size = s.length();
	vector<int> pnt;
	vector<bool> change(size, false);
	for(int i = 0; i < size - 1; i++) {
		if(s[i] == 'R' && s[i + 1] == 'L') {
			pnt.push_back(i);
		}
	}
	for(int i = 0; i < size - 1; i++) {
		if(s[i] == 'L' && s[i + 1] == 'R') {
			change[i + 1] = true;
		}
	}
	vector<int> ans(size, 0);
	int cnt = 0;
	for(int i = 0; i < size; i++) {
		if(change[i]) cnt++;
		if((pnt[cnt] - i) % 2) {
			ans[pnt[cnt] + 1]++;
		}else{
			ans[pnt[cnt]]++;
		}
	}
	for(int i = 0; i < size; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}