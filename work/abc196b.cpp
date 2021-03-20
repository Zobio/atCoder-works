#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	string a;
	cin >> a;
	for(int i = 0; i < a.length(); i++) {
		if(a[i] == '.')
			return 0;
		else
			cout << a[i];
	}
}