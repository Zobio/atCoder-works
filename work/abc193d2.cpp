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
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;} cout << endl
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF (1LL << 60)
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

vll ss(10), tt(10);

template<typename T>
T mpow(T a, T n, T m) {
	/*a^n % mを返す
	(例)
	pow(2, 10, 1000) --> 24
	計算量はlog(n)
	*/
	T ret = 1;
	while(n > 0) {
		if (n & 1) ret = ret * a % m;
		a = a % m * a % m;
		n >>= 1;
	}
	return ret;
}

bool f() {
	ll a = 0, b = 0;
	reps(i, 9) a += i * mpow(10ll, ss[i], MOD);
	reps(i, 9) b += i * mpow(10ll, tt[i], MOD);
	return a > b;
}

int main() {
	setcout(15);
	ll k; cin >> k;
	string s, t; cin >> s >> t;
	rep(i, 4) ss[s[i] - '0']++; rep(i, 4) tt[t[i] - '0']++;
	vll r(10, k);
	reps(i, 9) r[i] -= ss[i]; reps(i, 9) r[i] -= tt[i];
	ll sum = k * 9 - 8;
	ld ans = 0;
	reps(i, 9) reps(j, 9) {
		ld po = (ld)r[i] / sum;
		r[i]--;
		if(r[i] < 0) {r[i]++; continue;}
		po *= (ld)r[j] / (sum - 1);
		r[j]--;
		if(r[j] < 0) {r[i]++; r[j]++; continue;} 
		ss[i]++; tt[j]++;
		if(f()) ans += po;
		r[i]++; r[j]++; ss[i]--; tt[j]--;
	}
	cout << ans << endl;
}