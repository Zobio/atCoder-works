#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int a, b;
	cin >> a >> b;
	if(a > 12) cout << b << endl;
	else if(a > 5) cout << b / 2 << endl;
	else cout << 0 << endl;
}