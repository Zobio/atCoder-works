#include<bits/stdc++.h>
using namespace std;

long long GetDigit(long long b) {
	long long digit = 0;
	while (b != 0){
		b /= 10;
		digit++;
	}
	return digit;
}

int main() {
	long long a, b, x;
	cin >> a >> b >> x;
	long long ans = 1000000000;
	long long fAns = 0;
	long long m;
	while(ans - fAns > 1){
		m = (ans + fAns) / 2;
		if(a * m + b * GetDigit(m) > x){
			ans = m;
		}else{
			fAns = m;
		}
	}
	if (a * ans + b * GetDigit(ans) > x)
	{
		ans--;
	}
	if (ans > 1000000000)
		ans = 1000000000;
	cout << ans << endl;
}