#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n = 0;
	cin >> n;
	cout << typeid(n).name() << endl;
	cout << fixed << setprecision(10) << typeid(sqrt(n)).name() << " " << sqrt(n) << endl;
	cout << fixed << setprecision(10) << typeid((long long)sqrt(n)).name() << " " << (long long)sqrt(n) << endl;
}
