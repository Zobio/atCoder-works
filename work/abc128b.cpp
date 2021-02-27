#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<pair<string, int>> res(n);
	for(int i = 0; i < n; i++) {
		cin >> res[i].first >> res[i].second;
	}
	vector<pair<string, int>> ori = res;
	sort(res.begin(), res.end());
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(ori[i].first == res[j].first && ori[i].second == res[j].second)
			cout << i + 1 << endl;
		}
	}
}