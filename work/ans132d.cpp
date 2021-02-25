#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

int C[3000][3000];

int c(int x, int y) {
	if (y == 0 || x == y)return 1;
	else if (C[x][y] > 0)return C[x][y];
	else return C[x][y] = (c(x - 1, y - 1) + c(x - 1, y)) % mod;
}

signed main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		if (n - k < i) {
			cout << 0 << endl;
			continue;
		}
		cout << (c(n - k + 1, i + 1) * c(k - 1, i)) % mod << endl;
	}
}
