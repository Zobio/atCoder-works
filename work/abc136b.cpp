#include<bits/stdc++.h>
using namespace std;

int digit(int num) {
	int cnt = 0;
	while(num >= 10) {
		num /= 10;
		cnt++;
	}
	return cnt + 1;
} 

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(digit(i) % 2) ans++;
	}
	cout << ans << endl;
}