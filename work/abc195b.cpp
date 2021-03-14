#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int a, b, w, ans1, ans2;
	cin >> a >> b >> w;
	w *= 1000;
	int wCopy = w;
	int cnt = 0;
	while(wCopy > 0) {
		wCopy -= b;
		cnt++;
	}
	if(wCopy == 0) ans1 = cnt;
	else {
		wCopy *= -1;
		if(cnt * (b - a) >= wCopy) ans1 = cnt;
		else ans1 = -1;
	}
	wCopy = w, cnt = 0;
	while(wCopy > 0) {
		wCopy -= a;
		cnt++;
	}
	if(wCopy == 0) ans2 = cnt;
	else{
		wCopy += a;
		cnt--;
		if(cnt * (b - a) >= wCopy) ans2 = cnt;
		else ans2 = -1;
	}
	if(ans1 == -1 || ans2 == -1) {
		cout << "UNSATISFIABLE" << endl;
	}else{
		cout << ans1 << " " << ans2 << endl;
	}
}