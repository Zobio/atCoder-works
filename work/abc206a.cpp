#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	double n;
	cin >> n;
	int x = floor(n * 1.08);
	if(x < 206) cout << "Yay!" << endl;
	else if(x == 206) cout << "so-so" << endl;
	else cout << ":(" << endl;
}