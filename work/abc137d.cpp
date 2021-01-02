#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long a, b;
	priority_queue<long long> pnt;
	long long aoki = 0;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		pnt.push(a * 2 + b);
		aoki += a;
	}
	long long cnt = 0;
	while(aoki >= 0) {
		aoki -= pnt.top();
		pnt.pop();
		cnt++;
	}
	cout << cnt << endl;
}