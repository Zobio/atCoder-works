#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007

int main() {
	string x, y;
	cin >> x >> y;
	map<string, bool> mp;
	mp["0"] = false;
	mp["1"] = false;
	mp["2"] = false;
	mp[x] = true, mp[y] = true;
	if(x == y) cout << x << endl;
	else if(!mp["0"]) cout << 0 << endl;
	else if(!mp["1"]) cout << 1 << endl;
	else cout << 2 << endl;
}