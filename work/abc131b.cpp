#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, l;
	cin >> n >> l;
	int eat;
	if(l > 0) {
		eat = l;
	}
	else if(n - abs(l) > 0) {
		eat = 0;
	}
	else{
		eat = n + l - 1;
	}
	long ans = 0;
	for(int i = l; i < l + n; i++) {
		if(i != eat) ans += i;
	}
	cout << ans << endl;
}