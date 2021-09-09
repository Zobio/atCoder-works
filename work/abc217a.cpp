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
	string s, t; cin >> s >> t;
	for(int i = 0; i < min(s.length(), t.length()); i++) {
		if(s[i] < t[i]) {
			cout << "Yes" << endl; return 0;
		}
		if(s[i] > t[i]) {
			cout << "No" << endl; return 0;
		}
		if(i == s.length() - 1 || i == t.length() - 1) {
			cout << (s.length() > t.length() ? "No" : "Yes") << endl; return 0;
		}
	}
}