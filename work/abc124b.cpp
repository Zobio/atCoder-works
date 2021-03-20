#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	for(int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int ans = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(h[i] < h[j]) break;
			if(j == i - 1) ans++;
		}
	}
	cout << ans << endl;
}