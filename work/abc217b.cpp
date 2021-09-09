#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl;
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	map<string, bool> mp;
	mp["ABC"] = false;
	mp["AGC"] = false;
	mp["AHC"] = false;
	mp["ARC"] = false;
	rep(i, 3) {
		string s; cin >> s; mp[s] = true;
	}
	if (!mp["ABC"]) cout << "ABC" << endl;
	else if (!mp["AGC"]) cout << "AGC" << endl;
	else if (!mp["AHC"]) cout << "AHC" << endl;
	else cout << "ARC" << endl;
}