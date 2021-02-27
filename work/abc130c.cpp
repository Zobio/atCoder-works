#include <bits/stdc++.h>
using namespace std;

int main() {
	double w, h, x, y, n, ans = 0, cm1, cm2;
	cin >> w >> h >> x >> y;
	int p = 0;
	if(w / 2 == x && h / 2 == y) {
		p = 1; ans = w * h / 2;
	}else{
		ans = w * h / 2;
	}
	if(!p) {
		cout << fixed << setprecision(9) << ans << " ";
		cout << p << endl;
	}else{
		cout << fixed << setprecision(9) << ans << " ";
		cout << p << endl;
	}
}