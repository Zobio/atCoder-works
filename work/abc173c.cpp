#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int h, w, k;
	cin >> h >> w >> k;
	vector<vector<bool>> black(h, vector<bool>(w));
	int bl = 0;
	rep(i, h) {
		string s;
		cin >> s;
		rep(j, w) {
			if(s[j] == '#') black[i][j] = true, bl++;
			else black[i][j] = false;
		}
	}
	int ans = 0;
	for(int bits1 = 0; bits1 < pow(2, h); bits1++) {
		for(int bits2 = 0; bits2 < pow(2, w); bits2++) {
			int cnt = bl;
			vector<vector<bool>> done(h, vector<bool>(w, false));
			rep(i, h) if((bits1 >> i) & 1) {
				rep(j, w) if (black[i][j] && !done[i][j]) cnt--, done[i][j] = true;
			}
			rep(i, w) if((bits2 >> i) & 1) {
				rep(j, h) if (black[j][i] && !done[j][i]) cnt--, done[j][i] = true;
			}
			if(cnt == k) ans++;
		}
	}
	cout << ans << endl;
}