#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> l(n);
	for(int i = 0; i < n; i++) {
		cin >> l[i];
	}
	sort(l.begin(), l.end());
	long long cnt = 0;
	for(int a = 0; a < n; a++) {
		for(int b = a + 1; b < n; b++) {
			for(int c = b + 1; c < n; c++) {
				if(l[a] + l[b] > l[c] && l[b] + l[c] > l[a] && l[c] + l[a] > l[b]) {
					cnt++;
				}else{
					break;
				}
			}
		}
	}
	cout << cnt << endl;
}