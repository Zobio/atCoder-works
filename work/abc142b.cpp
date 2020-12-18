#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	int tmp;
	for(int i = 0; i < n; i++) {
		cin >> tmp;
		if(tmp >= k) cnt++;
	}
	cout << cnt << endl;
}