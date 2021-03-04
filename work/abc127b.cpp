#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	ull r, d, x;
	cin >> r >> d >> x;
	for(int i = 0; i < 10; i++) {
		x = x * r - d;
		cout << x << endl;
	}
}