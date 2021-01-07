#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, a, cnt = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a;
		if(a != i + 1)cnt++;
	}
	if(cnt < 3)cout << "YES" << endl;else cout << "NO" << endl;
}