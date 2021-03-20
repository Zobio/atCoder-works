#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int h, w, a, b, nowA, nowB;
ll ans = 0;

bool solve(int x, int y, vector<vector<bool>> used) {
	if(used[x][y]) return false;
	if(fill)
}

int main() {
	cin >> h >> w >> a >> b;
	nowA = a; nowB = b;
	vector<vector<bool>> used(h, vector<bool>(w));
	solve(0, 0, used);
	cout << ans << endl;
}