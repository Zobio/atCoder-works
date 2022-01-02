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
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 1000000007LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ull l, r; cin >> l >> r;
	ull di_l = 0, di_r = 0, cur = 1;
	while(cur * 10 <= l) di_l++, cur *= 10;
	cur = 1;
	while(cur * 10 <= r) di_r++, cur *= 10;
	//di_l, di_rは10^p > l, 10^q > rをそれぞれ満たす最小のp, q
	ull ans = 0;
	for(ll digit = di_l; digit <= di_r; digit++) {
		ull st = 1, en = 1, n = 1;
		rep(i, digit) n *= 10; n *= 9;
		ull ncp = n / 9 * 10;
		if(digit == di_l) n -= l - ncp / 10;
		if(digit == di_r) n -= ncp - r - 1;
		if(digit == di_l) st = l;
		else rep(i, digit) st *= 10;
		if(digit == di_r) en = r;
		else {rep(i, digit + 1) en *= 10; en--;}
		ll st_en = st + en;
		if(n % 2 == 0) n /= 2;
		else if(st_en % 2 == 0) st_en /= 2;
		n %= MOD; st_en %= MOD;
		ans = (ans + (n * st_en % MOD * (digit + 1) % MOD)) % MOD;
	}
	cout << ans << endl;
}