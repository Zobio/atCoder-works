#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define all(a) (a).begin(), (a).end()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	string n; cin >> n;
	ll k; cin >> k;
	string ans = "";
	rep(_, k) {
		ll num = 0;
		rep(i, n.size()) {
			num *= 8ll;
			num += n[i] - '0';
		}
		n = "";
		while(num) {
			n += to_string(num % 9);
			num /= 9ll;
		}
		reverse(all(n));
		rep(i, n.size()) if(n[i] == '8') n[i] = '5';
	}
	if(n == "") cout << 0 << endl;
	else cout << n << endl;
}