#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	if(d * c == b) {
		cout << (a == 0 ? 0 : -1) << endl;
	}else{
		cout << (a / (d * c - b) < (double)0 ? -1 : ceil(a / (d * c - b))) << endl;
	}
}