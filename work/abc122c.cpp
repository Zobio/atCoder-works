#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<pair<int, int>> lr(q);
	for(int i = 0; i < q; i++) {
		cin >> lr[i].first >> lr[i].second;
		lr[i].first--; lr[i].second--;
	}
	vector<int> ac(n);
	for(int i = 0; i < n - 1; i++) {
		if(s[i] == 'A' && s[i + 1] == 'C') ac[i] = 1;
	}
	vector<int> rui(n + 1, 0);
	for(int i = 0; i < n + 1; i++) {
		rui[i + 1] = rui[i] + ac[i];
	}
	for(int i = 0; i < q; i++) {
		if(ac[lr[i].second]) cout <<  rui[lr[i].second + 1] - rui[lr[i].first]  - 1 << endl;
		else cout << rui[lr[i].second + 1] - rui[lr[i].first] << endl;
	}
}