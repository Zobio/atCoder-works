#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> xy(n);
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		xy[i] = make_pair(a, b);
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			for(int k = j + 1; k < n; k++) {
				if (xy[i].second - xy[j].second == 0 || xy[i].second - xy[k].second == 0) {
					if (xy[i].second == xy[j].second && xy[j].second == xy[k].second) {
						cout << "Yes" << endl;
						return 0;
					}else{
						continue;
					}
				}
					if ((double)(xy[i].first - xy[j].first) / (xy[i].second - xy[j].second) == (double)(xy[i].first - xy[k].first) / (xy[i].second - xy[k].second))
					{ 
						cout << "Yes" << endl;
						return 0;
					}
			}
		}
	}
	cout << "No" << endl;
}