#include <bits/stdc++.h>
using namespace std;

int main () {
	string x;
	long long m;
	cin >> x >> m;
	sort(x.rbegin(), x.rend());
	int max = x[0] - '0';
	max++;
	unsigned long long sum = 0;
	long long ans = 0;
	while(true) {
		for(int i = 0; i < x.size(); i++) {
			sum += (x[x.size() - i - 1] - '0') * pow(max, i);
		}
		if(sum <= m && sum != 0) {
			ans++;
			max++;
			//cout << max - 1 << " " <<  sum << endl;
			sum = 0;
		}else{
			//cout << sum << endl;
			cout << ans << endl;
			return 0;
		}
	}
}