#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> s(h, vector<int>(w));
	for(int i = 0; i < h; i++) {
		string tmp;
		cin >> tmp;
		for(int j = 0; j < w; j++) {
			if(tmp[j] == '#')
			s[i][j] = 1;
			else
			s[i][j] = 0;
		}
	}
	vector<vector<int>> l(h, vector<int>(w));
	vector<vector<int>> r(h, vector<int>(w));
	vector<vector<int>> d(h, vector<int>(w));
	vector<vector<int>> u(h, vector<int>(w));
	vector<vector<int>> sum(h, vector<int>(w));
	int ans = 0;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(s[i][j]) {
				l[i][j] = 0;
				u[i][j] = 0;
			}else{
				if(i == 0){
					u[i][j] = 1;
				}else{
					u[i][j] = u[i - 1][j] + 1; 
				}
				if(j == 0) {
					l[i][j] = 1;
				}else{
					l[i][j] = l[i][j - 1] + 1;
				}
			}
		}
	}
	for(int i = h - 1; i >= 0; i--) {
		for(int j = w - 1; j >= 0; j--) {
			if(s[i][j]) {
				r[i][j] = 0;
				d[i][j] = 0;
			}else{
				if(i == h - 1) {
					d[i][j] = 1;
				}else{
					d[i][j] = d[i + 1][j] + 1;
				}
				if(j == w - 1) {
					r[i][j] = 1;
				}else{
					r[i][j] = r[i][j + 1] + 1;
				}
			}
			sum[i][j] = max(l[i][j] + r[i][j] + d[i][j] + u[i][j] - 3, 0);
			//cout << i << " " << j << "  " << l[i][j] << " " << r[i][j] << " " << d[i][j] << " " << u[i][j] << "  " <<  sum[i][j] << endl;
			if(sum[i][j] > ans) ans = sum[i][j];
		}
	}
	cout << ans << endl;
}