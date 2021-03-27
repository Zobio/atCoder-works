#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int h, w, x, y;
	cin >> h >> w >> x >> y;
	x--; y--;
	vector<string> s(h);
	for(int i = 0; i < h; i++) {
		cin >> s[i];
	}
	ll ans = -3;
	for(int i = x; i >= 0; i--) {
		if(s[i][y] == '#')break;
		else ans++;
	}
	for(int i = x; i < h; i++) {
		if(s[i][y] == '#')break;
		else ans++;
	}
	for(int i = y; i >= 0; i--) {
		if(s[x][i] == '#')break;
		else ans++;
	}
	for(int i = y; i < w; i++) {
		if(s[x][i] == '#')break;
		else ans++;
	}
	cout << ans << endl;
}