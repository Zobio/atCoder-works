#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	if(n <= 125) cout << 4 << endl;
	else if(n <= 211) cout << 6 << endl;
	else cout << 8 << endl;
}