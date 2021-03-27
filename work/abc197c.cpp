#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 1073741825;
	for(ull bits = 0; bits < (ull)pow(2, n); bits++) {
		vector<int> nums;
		vector<bool> shikiri(n, false);
		int next = -1;
		for(int i = 0; i < n; i++) {
			if(bits & (1 << i)) 
				shikiri[i] = true;
		}
		for(int i = 0; i < n; i++) {
			if(next == -1) next = a[i];
			else next |= a[i];
			if(shikiri[i]) {
				nums.push_back(next);
				next = -1;
			}
		}
		if(next != -1) nums.push_back(next);
		int now = -1;
		for(int i = 0; i < nums.size(); i++) {
			if(now == -1) now = nums[i];
			else now ^= nums[i];
		}
		if(now != -1 && ans > now) ans = now;
	}
	cout << ans << endl;
}