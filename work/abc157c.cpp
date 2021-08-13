#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> sc;
	rep(i, m) {
		int a, b; cin >> a >> b;
		sc.push_back(make_pair(a, b));
	}
	sort(sc.begin(), sc.end());
	for(int i = 0; i < m; i++) {
		if(sc[i].first == 1 && sc[i].second == 0 && n > 1) {
			cout << -1 << endl; return 0;
		}
	}
	for(int i = 0; i < m - 1; i++) {
		if(sc[i].first == sc[i + 1].first && sc[i].second != sc[i + 1].second){
			cout << -1 << endl; return 0;
		}
	}
	bool con = false;
	for(int i = 0; i <= 999; i++) {
		if(i == 0 && n != 1) continue;
		else if(i == 0 && n == 1);
		else if((int)floor(log10(i)) + 1 != n) continue;
		for(int j = 0; j < m; j++) {
			int cp = i, fir = n - sc[j].first;
			while(fir--) cp /= 10;
			if(cp % 10 != sc[j].second) con = true;
		}
		if(con) {con = false; continue;}
		cout << i << endl; return 0;
	}
}