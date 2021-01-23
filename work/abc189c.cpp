#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	long long tmp = 0, sum = 0, ans = 0;
	for(int i = 0; i < b.size(); i++) {
		for(int j = 0; j < n; j++) {
			if(a[j] >= b[i]) {
				tmp += b[i];
			}else{
				if(tmp > sum) {
					sum = tmp;
				}
				tmp = 0;
			}
		}
		if(tmp > sum) {
			sum = tmp;
		}
		if(ans < sum) {
			ans = sum;
		}
		sum = 0;
		tmp = 0;
	}
	cout << ans << endl;
}