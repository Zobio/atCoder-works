#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> c(n);
	map<int, int> m;
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}
	//初出のキャンディの位置を求める
	for(int i = n - 1; i >= 0; i--) {
		m[c[i]] = i;
	}
	ll cnt = 0;
	for(int i = 0; i < k; i++) {
		if(m[c[i]] == i) cnt++;
		else if(i - m[c[i]] >= k) cnt++, m[c[i]] = i;
		else m[c[i]] = i;
	}
	ll res = cnt;
	for(int i = k; i < n; i++) {
		//新しい部分に対する操作
		if(m[c[i]] == i) cnt++;
		else if(i - m[c[i]] > k) cnt++, m[c[i]] = i;
		else m[c[i]] = i;

		//後ろの部分に対する操作
		if(m[c[i - k]] == i - k) cnt--;
		res = max(cnt, res);
	}
	cout << res << endl;
}