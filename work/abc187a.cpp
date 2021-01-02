#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int aa = 0, bb = 0;
	aa += a / 100;
	a -= a / 100 * 100;
	aa += a / 10;
	a -= a / 10 * 10;
	aa += a;
	bb += b / 100;
	b -= b / 100 * 100;
	bb += b / 10;
	b -= b / 10 * 10;
	bb += b;
	cout << (aa > bb ? aa:bb) << endl;
}