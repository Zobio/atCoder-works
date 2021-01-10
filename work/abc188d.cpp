#include <bits/stdc++.h>
using namespace std;
#define day 1000000002

int main() {
	int n; long long C;
	cin >> n >> C;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	vector<long long> change(day);
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--;
		change[a[i]] += c[i];
		change[b[i] + 1] -= c[i];
	}
	long long tmp = 0;
	long long ans = 0;
	for(long long i = 0; i < day - 1; i++) {
		tmp += change[i];
		ans += min(C, tmp);
	}
	cout << ans << endl;
}