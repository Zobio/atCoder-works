#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define co(a) cout << a << endl

int main() {
	int n;
	cin >> n;
	vector<vector<int>> lo(210000);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if(a > b) swap(a, b);
		lo[a].push_back(b);
	}
	int low = 0;
	rep(i, n) sort(lo[i].begin(), lo[i].end());
	vector<int> res;
	while(upper_bound(lo[0].begin(), lo[0].end(), low) != lo[0].end()) {
		vector<int> ans; int now;
		ans.push_back(0);
		ans.push_back(*upper_bound(lo[0].begin(), lo[0].end(), low));
		now = low = ans.back();
		while (upper_bound(lo[now].begin(), lo[now].end(), now) != lo[now].end()) {
			ans.push_back(*upper_bound(lo[now].begin(), lo[now].end(), now));
			now = ans.back();
		}
		for(int i = 0; i < ans.size(); i++) res.push_back(ans[i] + 1);
		for(int i = ans.size() - 2; i >= 1; i--) res.push_back(ans[i] + 1);
	}
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << 1 << endl;
}