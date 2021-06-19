#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define INF 100000000000000

int main()
{
	while(true){
	ull a = 1, b = 2;
	ull tmp = b;
	b = a * b + 1;
	a = tmp;
	cout << b << endl;
	}
}
