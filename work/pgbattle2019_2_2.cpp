#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, n) for (long long i = 0; i < n; i++)
#define reps(i, n) for (long long i = 1; i <= n; i++)
#define rrep(i, n) for (long long i = n - 1; i >= 0; i--)
#define rreps(i, n) for (long long i = n; i >= 1; i--)
#define reep(i, a, b) for(long long i = a; i < b; i++)
#define fore(i, a) for (auto& i : a)
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvvll vector<vector<vector<long long>>>
#define vvvvll vector<vector<vector<vector<long long>>>>
#define pll pair<long long, long long>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define arrcout(a) for(size_t i = 0; i < a.size(); i++) cout << (i ? " " : "") << a.at(i); cout << endl
#define arrcout2(a) for(size_t i = 0; i < a.size(); i++) {for(size_t j = 0; j < a[i].size(); j++) cout << (j ? " " : "") << a.at(i).at(j); cout << endl;}
#define setcout(n) cout << setprecision(n) << fixed
#define YESS {printf("Yes\n"); return 0;}
#define NOO {printf("No\n"); return 0;}
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define mint modint998244353
#define INF (1LL << 60)
#define PI acos(-1.0)
//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ll n, m; cin >> n >> m;
	ll a, b, c; cin >> a >> b >> c;
	if(a + b + c == 0) { //例外
		if(m == 0) cout << n << " " << 0 << " " << 0 << endl;
		else cout << -1 << " " << -1 << " " << -1 << endl;
		return 0;
	}
	if(a == 0 && b == 0) {
		if(m % c == 0 && m / c == n) cout << 0 << " " << 0 << " " << n << endl;
		else cout << -1 << " " << -1 << " " << -1 << endl;
		return 0;
	}
	if(a == 0 && c == 0) {
		if(m % b== 0 && m / b == n) cout << 0 << " " << n << " " << 0 << endl;
		else cout << -1 << " " << -1 << " " << -1 << endl;
		return 0;
	}
	if(b == 0 && c == 0) {
		if(m % a == 0 && m / a == n) cout << n << " " << 0 << " " << 0 << endl;
		else cout << -1 << " " << -1 << " " << -1 << endl;
		return 0;
	}
	if(a == 0) {
		for(ll i = 0; i <= (m + b - 1) / b; i++) {
			ll rest = m - b * i;
			if(rest % c == 0 && i + (rest / c) <= n) {cout << n - (i + (rest / c)) << " " << i << " " << rest / c << endl; return 0;}
		}
		cout << -1 << " " << -1 << " " << -1 << endl; return 0;
	}
	for(ll i = 0; i <= (m + a - 1) / a; i++) {
		if(b == c) {
			if((m - a * i) % b != 0) continue;
			else cout << i << " " << (m - a * i) / b << " " << 0 << endl;
			return 0;
		}else{
			if((m + (b - a) * i - b * n) % (c - b) != 0) continue;
			ll k = (m + (b - a) * i - b * n) / (c - b);
			if(k < 0) continue;
			ll j = n - i - k;
			if(j < 0) continue;
			cout << i << " " << j << " " << k << endl;
			return 0;
		}
	}
	cout << -1 << " " << -1 << " " << -1 << endl;
}