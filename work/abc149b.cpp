#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b, k;
	long long ansA = 0, ansB = 0;
	cin >> a >> b >> k;
	if(a >= k) {
		ansA = a - k;
		ansB = b;
	}else{
		ansA = 0;
		ansB = (a + b) - k;
	}
	if(ansB < 0)
	ansB = 0;
	cout << ansA <<" " <<  ansB << endl;
}