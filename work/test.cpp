#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	vector<vector<int>> a(10, vector<int>(10));
	if(a[10].empty()) cout << "YES" << endl;
	else cout << "NO" << endl;
	cout << a[10].size() << endl;
	cout << a[10][0] << endl;
}