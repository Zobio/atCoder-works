#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	int tmp = 0;
	cin >> n >> t;
	vector<int> a(n);
	for(int i = 0; i< n; i++) {
		cin >> a[i];
		tmp += a[i];
	}
	sort(a.begin(), a.end());
	if(a[0] > t) {
		cout << "0" << endl;
		return 0;
	}
	else if(t >= tmp) {
		cout << tmp << endl;
		return 0;
	}
	int sum = 0;
	int qCopy = 0;
	int ans = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(a[i] > t)
		continue;

		sum += a[i];
			for(int q = 0; q < i; q++) {
				qCopy = q;
				for(int j = i - 1; j >= 0; j--) {
					qCopy--;
					if(sum + a[j] <= t && qCopy < 0)
					sum += a[j];
				}
				if(ans < sum) {
				ans = sum;
				}
				sum = 0;
			}
	}


			cout << ans << endl;

}