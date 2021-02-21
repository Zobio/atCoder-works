#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>> s(h, vector<char>(w));
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> s[i][j];
		}
	}
	int cnt = 0;
	int ans = 0;
	for(int i = 0; i < h - 1; i++) {
		for(int j = 0; j < w - 1; j++) {
			if(s[i][j] == '#')cnt++;
			if(s[i][j + 1] == '#')cnt++;
			if(s[i + 1][j] == '#')cnt++;
			if(s[i + 1][j + 1] == '#')cnt++;
			if(cnt & 1) ans++;
			cnt = 0;
		}
	}
	cout << ans << endl;
}
