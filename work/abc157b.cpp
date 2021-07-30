#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	vector<vector<int>> a(3, vector<int>(3));
	vector<bool> done(100, false);
	rep(i, 3) rep(j, 3) {
		int x; cin >> x; x--;
		a[i][j] = x;
	}
	int n;
	cin >> n;
	vector<int> b(n);
	rep(i, n) {
		int x; cin >> x; x--;
		done[x] = true;
	}
	rep(i, 3) {
		bool flag = true;
		rep(j, 3) {
			if(!done[a[i][j]]) flag = false;
		}
		if(flag) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	rep(i, 3) {
		bool flag = true;
		rep(j, 3) {
			if(!done[a[j][i]]) flag = false;
		}
		if(flag) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	if ((done[a[0][0]] && done[a[1][1]] && done[a[2][2]]) || (done[a[0][2]] && done[a[1][1]] && done[a[2][0]])) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}