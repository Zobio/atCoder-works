#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b && b == c && c == a)
		cout << a << endl;
	else if (a != b && b != c && c != a)
		cout << 0 << endl;
	else if (a != b && b != c)
		cout << b << endl;
	else if (a != b && a != c)
		cout << a << endl;
	else
		cout << c << endl;
}