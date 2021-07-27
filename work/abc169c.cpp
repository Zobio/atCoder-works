#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ull a;
	cin >> a;
	string b;
	cin >> b;
	ull c = 0;
	bool flag = false;
	for(int i = b.length() - 1; i >= 0; i--) {
		if(b[i] == '.') {flag = true;continue;}
		c += (ull)pow(10, -i + (int)b.length() - 1 - flag) * (ull)(b[i] - '0');
		//cout << pow(10, -i + (int)b.length() - 1 - flag)  << " " << c << endl;
	}
	cout << a * c / 100 << endl;
}