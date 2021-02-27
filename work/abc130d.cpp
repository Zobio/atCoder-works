#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main() {
	int n; ull k;
	cin >> n >> k;
	vector<ull> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ull sum = 0, ans = 0;
	int r = 0;
	for(int i = 0; i < n; i++) {
		while(sum < k) {
			if(r == n) break;
			else {
				sum += a[r];
				r++;
			}	
		}
		if(sum < k) break;
		ans += n - r + 1;
		sum -= a[i];
	}
	cout << ans << endl;
}