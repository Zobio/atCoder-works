#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	priority_queue<string> pq;
	int n;
	cin >> n;
	if(n & 1) {
		return 0;
	}
	for(int bits = 0; bits < (1 << n); bits++) {
		int bitsCnt = 0;
		for(int i = 0; i < n; i++) {
			if((bits >> i) & 1) bitsCnt++; //右ビットシフト！
		}
		if(bitsCnt != n / 2) continue;
		string s = ""; int stock = 0; bool flag = true;
		for(int i = 0; i < n; i++) {
			if((bits >> i) & 1) s += "(", stock++;
			else s += ")", stock--;
			if(stock < 0) flag = false;
		}
		if(flag & stock == 0) pq.push(s);
	}
	vector<string> ans;
	while(!pq.empty()) {
		ans.push_back(pq.top());
		pq.pop();
	}
	reverse(ans.begin(), ans.end());
	for(auto a : ans) cout << a << endl;
}