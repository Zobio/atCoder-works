#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<ll>> m(h, vector<ll>(w));
	vector<ll> s1(h);
	vector<ll> s2(w);
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> m[i][j];
			s1[i] += m[i][j];
			s2[j] += m[i][j];
		}
	}
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cout << s1[i] + s2[j] - m[i][j] << " ";
		}
		cout << endl;
	}
}