#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 1000000007LL
#define INF 1LL << 60

ll n, a, b, c, d;
string s;

bool ok(ll start, ll end) {
	for(ll i = start; i + 1 <= end; i++) if(s[i] == '#' && s[i + 1] == '#') return false;
	return true;
}

int main() {
 	cin >> n >> a >> b >> c >> d;
 	cin >> s;
	s = '#' + s + '#';
	if (!ok(a, c) || !ok(b, d)) {cout << "No" << endl;return 0;}
	if(c < d) {cout << "Yes" << endl; return 0;}
	bool flag = false;
	for(ll i = b; i <= d; i++) if(s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') flag = true;
	if(!flag) {cout << "No" << endl; return 0;}
	cout << "Yes" << endl; return 0;
}