#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

int main() {
	int n;
	cin >> n;
	vector<int> w(n);
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		cin >>w[i];
		sum += w[i];
	}
	ll ave = sum / 2;
	ll sumcp = sum;
	sum = 0;
	ll ans = 1e10;
	for(int i = 0; i < n; i++) {
		sum += w[i];
		if(abs(sum - ave) < abs(ans - ave))
		ans = sum;
	}
	cout << abs(ans - sumcp + ans) << endl;
}