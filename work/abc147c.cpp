#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> a(n);
	for(int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		for(int j = 0; j < tmp; j++) {
			int x, y;
			cin >> x >> y;
			x--;
			a[i].push_back(make_pair(x, y));
		}
	}
	int ans = 0;
	for(int bits = 0; bits < pow(2, n); bits++) {
		vector<int> sus(n, -1);
		bool flag = true;
		for(int i = 0; i < n; i++) {
			if(!((bits >> i) & 1)) continue;
			for(int j = 0; j < a[i].size(); j++) {
				if(sus[a[i][j].first] == -1) {
					sus[a[i][j].first] = a[i][j].second;
				}else{
					flag = sus[a[i][j].first] == a[i][j].second ? flag : false;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			if(sus[i] == -1) continue;
			if(sus[i] != ((bits >> i) & 1)) flag = false; 
		}
		if(!flag) continue;
		int sum = 0;
		for(int i = 0; i < n; i++) {
			sum += (bits >> i) & 1;
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}