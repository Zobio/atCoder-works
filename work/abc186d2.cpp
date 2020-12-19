#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long ans = 0;
	int cnt = 0;
	int point = 0;
	for(int i = 0; i < n - 1; i++) {
		point = a.size() - cnt - n;
		cnt = 0;
		cout << "point" << point << endl;
		for(int j = 0; j < n - i - 1; j++) {
			a.push_back(a[point + 1] - a[point]);
			cnt++;
			ans += abs(a[point + 1] - a[point]);
			cout << abs(a[point + 1] - a[point]) << endl;
			point++;
		}
	}
	cout << ans << endl;
}