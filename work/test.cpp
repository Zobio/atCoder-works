#include <bits/stdc++.h>
using namespace std;

int main()
{
	for(int i = 0; i < 64; i++) {
		cout << (1 << i) << endl;
		cout << (1LL << i) << endl;
		cout << ((long)1 << i) << endl;
	}
}
