#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long sq = sqrt(n);
	long long ansA, ansB;
	for(int i = sq; i > 0; i--) {
		if(!(n % i)) {
			ansA = i;
			ansB = n / i;
			break;
		}
	}
	cout << ansA + ansB - 2 << endl;
}