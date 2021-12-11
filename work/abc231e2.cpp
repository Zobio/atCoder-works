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
#define setcout(n) cout << setprecision(n) << fixed
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define MOD 998244353LL
#define INF 1LL << 60
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

ll n, x, ans = INF;
vll a; 

void calc(ll m, ll cnt) {
	while(m){
		auto it = upper_bound(all(a), m); it--;
		cnt += m / *it;
		m -= (m / *it) * *it;
	}
	chmin(ans, cnt);
}

int main() {
	cin >> n >> x;
	a.resize(n); rep(i, n) cin >> a[i];
	ll c = 0;
	while(x) {
		auto it = upper_bound(all(a), x);
		for(auto i = a.begin(); i != it; i++) {
			if(i != a.end()) calc(*i * (ceil((ld)(x / (*i))) - x), c + (x / *i)); 
		}
		if(it != a.begin()) it--;
		c += x / *it;
		x -= (x / *it) * *it;
	}
	chmin(ans, c);
	cout << ans << endl;
}