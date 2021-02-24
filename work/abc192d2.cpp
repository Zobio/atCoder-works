#include <bits/stdc++.h>
using namespace std;

string x;
long long m;

bool check(long long md) {
	unsigned long long sum = 0;
	for(long long i = 0; i < x.length(); i++) {
		//cout << "sum: " << sum << endl;
		sum = sum * md + (x[i] - '0');
		if(sum > m) {
			//cout << "return" << endl;
			 return false;
		}
	}
	return true;
}

int main() {
	cin >> x >> m;
	sort(x.rbegin(), x.rend());
	long long low = x[0] - '0';
	long long d = low;
	if(x.length() == 1) {
		cout << (low <= m) << endl;
		return 0;
	}
	long long high = 2e18;
	while(low < high) {
		long long md = (low + high) / 2;
		if(check(md)) {
			low = md + 1;
		}else{
			high = md;
		}
		//cout << "high: " << high << " low: " << low << endl;
	}
	//cout << high << " " << low << endl;
	cout << high - d - 1 << endl;
}