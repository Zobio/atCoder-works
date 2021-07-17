#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> c(n);
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}
	list<int> ls;
	for(int i = 0; i < k; i++) {
		ls.push_back(c[i]);
	}
	list<int> lsCp;
	lsCp = ls;
	lsCp.sort();
	lsCp.unique();
	int ans = (int)lsCp.size();
	for(int i = k; i < n; i++) {
		ls.pop_front();
		ls.push_back(c[i]);
		lsCp = ls;
		lsCp.sort();
		lsCp.unique();
		if((int)lsCp.size() > ans) ans = (int)lsCp.size();
	}
	cout << ans << endl;
}