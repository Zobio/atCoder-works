#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 1000000007LL
#define INF 1LL << 60

int main() {
	vector<string> s(3);
	rep(i, 3) cin >> s.at(i);
	string t; cin >> t;
	string ans = "";
	rep(i, t.size()) {
		ans += s[t[i] - '1'];
	}
	cout << ans << endl;
}