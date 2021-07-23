#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int a, b;
	cin >> a >> b;
	if(a <= b && b <= a * 6) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}