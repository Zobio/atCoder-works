#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main()
{
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << setprecision(10) << fixed <<  a + (c - a) * (b / (b + d)) << endl;
}