#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<pair<int, int>> bag;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		bag.push_back(make_pair(b * -1, a));
	}
	sort(bag.begin(), bag.end());
	vector<int> box(m);
	for(int i = 0; i < m; i++) {
		cin >> box[i];
	}
	for(int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--;r--;
		vector<int> bCopy;
		for(int j = 0; j < m; j++) {
			if(j < l || j > r)
				bCopy.push_back(box[j]);
		}
		sort(bCopy.begin(), bCopy.end());
		ll ans = 0;
		vector<bool> yet(bCopy.size(), true);
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < bCopy.size(); k++) {
				if(bag[j].second <= bCopy[k] && yet[k]) {
					ans += bag[j].first * -1;
					yet[k] = false;
					break;
				}
			}
		}
		cout << ans << endl;
	}
}