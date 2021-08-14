#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int t; cin >> t;
	bool flag = false;
	rep(_, t) {
		int n; cin >> n;
		set<int> box;
		rep(i, n) {
			int l, r; flag = false;
			cin >> l >> r; l--; r--;
			for(int j = l; j <= r; j++) {
				if(lower_bound(box.begin(), box.end(), j) == box.end()) {
					box.insert(j); flag = true; break;
				}
				if (*lower_bound(box.begin(), box.end(), j) != j) {
					box.insert(j); flag = true; break;
				}
			}
			if(!flag) { cout << "No" << endl; break;}
			if(i == n - 1) cout << "Yes" << endl;
		}
	}
}