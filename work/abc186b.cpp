#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	int a[h][w] = {};
	int sma = 101;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> a[i][j];
			if(sma > a[i][j])
			sma = a[i][j];
		}
	}
	long long cnt = 0;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cnt += a[i][j] - sma;
		}
	}
	cout << cnt << endl;
}