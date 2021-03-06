#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<vector<int>> spot(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		spot[a[i]].push_back(i);
	}
	bool fn = false;
	for(int i = 0; i < n; i++) {
		if(spot[i].empty()) {
			cout << i << endl;
			return 0;
		}
		for(int j = 0; j < spot[i].size(); j++) {
			if(j == 0) {
				if (spot[i][j] >= m) fn = true;
			}else{
				if(spot[i][j] - spot[i][j - 1] - 1 >= m) fn = true;
			}
			if(j == spot[i].size() - 1){
				if(n - 1 - spot[i][j] >= m) fn = true;
			}

			if(fn) {
				cout << i << endl;
				return 0;
			}
		}
	}
	cout << n << endl;
}