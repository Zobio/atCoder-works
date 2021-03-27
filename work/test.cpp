#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	cout << v.size() << endl;
	v[n].push_back(100000000);
	cout << v[n][0] << endl;
}